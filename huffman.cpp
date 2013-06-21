/* 
 * File:   huffman.cpp
 * Author: mihver1
 * 
 * Created on June 21, 2013, 1:30 PM
 */

#include "huffman.h"

huffman::huffman() {
}

huffman::~huffman() {
    delete tree;
}

void huffman::compress(std::string src, std::string dest) {
    size_t size = (size_t)filesize(src.c_str());
    std::ifstream input;
    huffman::buffered_writer output;
    output.open(dest);
    try {
        input.open(src.c_str(), std::ifstream::binary);
    } catch (std::exception e) {
        std::cerr << "Can't open file: " << e.what() <<std::endl;
    }
    while(! input.eof()) {
        char c;
        input.get(c);
        if(! input.eof()) {
            add_byte_frequency(c);
        }
    }
    build();
    input.clear();
    input.seekg(0);
    output.put((unsigned)size);
    output.put((unsigned)frequency.size());
    for(std::map<char, unsigned>::iterator i = frequency.begin(); i != frequency.end(); ++i){
        output.put(i->first);
        output.put(i->second);
    }
    while(! input.eof()) {
        char c;
        input.get(c);
        if(! input.eof()){
            std::vector<bool>* t = ans[c];
            //std::reverse(t->begin(), t->end());
            for(size_t i = 0; i < t->size(); ++i) {
                output.add(t->at(i));
            }
        }
    }
    output.close();
}

void huffman::uncompress(std::string src, std::string dest) {
    huffman::buffered_reader input;
    std::ofstream output;
    input.open(src);
    try {
        output.open(dest.c_str(), std::ofstream::binary);
    } catch (std::exception e) {
        std::cerr << "Can't open file: " << e.what() <<std::endl;
    }
    size_t size = input.get_int();
    size_t n = input.get_int();
    for(int i = 0; i < n; ++i) {
        char c = input.get_char();
        set_byte_frequency(c, input.get_int());
    }
    build();
    node* nd = tree;
    while(input.not_eof()) {
        bool b = input.get_bit();
        if(input.not_eof() && size) {
            if(b) {
                if(nd->one) {
                    nd = nd->one;
                } else {
                    --size;
                    output.put(nd->character);
                    nd = tree->one;
                }
            } else {
                if(nd->zero) {
                    nd = nd->zero;
                } else {
                    --size;
                    output.put(nd->character);
                    nd = tree->zero;
                }
            }
        }
    }
    if(!nd->zero && !nd->one) {
        --size;
        output.put(nd->character);
    }
    
    input.close();
}

void huffman::dfs(node* v, bool del = 0) {
    bool c = 0;
    if (v->zero) {
        c = 1;
        dfs(v->zero);
    }
    if (v->one) {
        c = 1;
        dfs(v->one);
    }
    if(!c) {
        ans[v->character] = v->sequence;
    }
}

void huffman::build() {
    for(std::map<char, unsigned>::iterator i = frequency.begin(); i!=frequency.end(); ++i) {
        node* a = new node(i->first, i->second);
        assert(a);
        huffman_queue.push(a);
    }
    if( huffman_queue.size() == 1) {
        node* a = huffman_queue.top();
        a->sequence->push_back(0);
    }
    while( huffman_queue.size() > 1) {
        node* a = huffman_queue.top();
        assert(a);
        huffman_queue.pop();
        node* b = huffman_queue.top();
        assert(b);
        huffman_queue.pop();
        node* c = join(a, b);
        assert(c);
        huffman_queue.push(c);
    }
    tree = huffman_queue.top();
    dfs(tree);
}

huffman::node::node():
        zero(0), one(0), character(0), frequency(0), sequence(new std::vector<bool>()){
}

huffman::node::node(char c, unsigned freq): 
        zero(0), one(0), character(c), frequency(freq), sequence(new std::vector<bool>()) {
}

huffman::node::~node() {
    if(zero)
        delete zero;
    if(one)
        delete one;
    if(sequence)
        delete sequence;
}

bool huffman::node_compare::operator ()(node* a, node* b) {
        return a->frequency > b->frequency;
}

void huffman::add_byte_frequency(char b) {
    ++frequency[b];
}

void huffman::set_byte_frequency(char b, unsigned freq) {
    frequency[b] = freq;
}

void huffman::node::push(bool b) {
    if(!zero && !one) {
        sequence->insert(sequence->begin(), b);
    }
    if(zero) {
        zero->push(b);
    }
    if(one) {
        one->push(b);
    }
}

huffman::node* huffman::join(huffman::node* a, huffman::node* b) {
    node* temp_node = new node(0, a->frequency + b->frequency);
    temp_node->zero = a;
    temp_node->one = b;
    temp_node->zero->push(0);
    temp_node->one->push(1);
    return temp_node;
}

huffman::buffered_writer::buffered_writer() {
    buffer = 0;
    size = 0;
}

void huffman::buffered_writer::open(std::string src) {
    try {
        out.open(src.c_str(), std::ofstream::binary);
    } catch (std::exception e) {
        std::cerr<<"Can't open file: "<<e.what()<<std::endl;
    }
}

void huffman::buffered_writer::add(bool b) {
    buffer |= b;
    ++size;
    if (size == 8) {
        out.put(buffer);
        out.flush();
        buffer = 0;
        size = 0;
    }
    buffer <<= 1;
}

void huffman::buffered_writer::put(char c) {
    out.put(c);
    out.put(' ');
}

void huffman::buffered_writer::put(unsigned c) {
    out<<c<<" ";
}

void huffman::buffered_writer::close() {
    if (size) {
       buffer <<= (8 - size -1);
       out.put((char)buffer);
    }
    out.close();
}

huffman::buffered_reader::buffered_reader():
        buffer(0), size(0){
}

void huffman::buffered_reader::open(std::string src) {
    try {
        in.open(src.c_str(), std::ifstream::binary);
    } catch (std::exception e) {
        std::cerr << "Can't open file: " << e.what() << std::endl;
    }
}

bool huffman::buffered_reader::get_bit() {
    if (size == 0) {
        in.get(buffer);
        if(!in.eof())
            size = 8;
        else
            return 0;
    }
    --size;
    return 0x1 & (buffer >> size);
}

char huffman::buffered_reader::get_char() {
    char c = in.get();
    in.get();
    return c;
}

unsigned huffman::buffered_reader::get_int() {
    unsigned t;
    in>>t;
    in.get();
    return t;
}

bool huffman::buffered_reader::not_eof() const {
    return !in.eof();// || size > 0;
}

void huffman::buffered_reader::close() {
    in.close();
}

std::ifstream::pos_type huffman::filesize(const char* filename) {
    std::ifstream in(filename, std::ifstream::in | std::ifstream::binary);
    in.seekg(0, std::ifstream::end);
    return in.tellg();
}