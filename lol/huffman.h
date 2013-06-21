/* 
 * File:   huffman.h
 * Author: mihver1
 *
 * Created on June 21, 2013, 1:30 PM
 */

#ifndef HUFFMAN_H
#define	HUFFMAN_H

#include<algorithm>
#include<string>
#include<cassert>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<fstream>
#include<exception>
#include<iostream>

class huffman {
public:
    huffman();
    virtual ~huffman();
    void compress(std::string src, std::string dest);
    void uncompress(std::string src, std::string dest);
private:
    class node {
    public:
        node* zero;
        node* one;
        char character;
        unsigned frequency;
        std::vector<bool> * sequence;
        
        node();
        node(char c, unsigned int freq);
        void push(bool b);
        virtual ~node();
    };
    
    node* tree;
    node* join(node* a, node* b);
    
    class node_compare {
    public:
        bool operator()(node* a, node* b);      
    };
    
    void dfs(node* v, bool del);
    
    std::map<char, unsigned> frequency;
    std::map<char, std::vector<bool>* > ans;
    std::priority_queue<node*, std::vector<node*>, node_compare> huffman_queue;
    
    void add_byte_frequency(char b);
    void set_byte_frequency(char b, unsigned freq);
    void build();
    
    class buffered_writer {
    public:
        buffered_writer();
        void open(std::string src);
        void add(bool b);
        void put(char c);
        void put(unsigned u);
        void close();
    private:
        char buffer;
        int size;
        std::ofstream out;
    };
    
    class buffered_reader {
    public:
        buffered_reader();
        void open(std::string src);
        bool get_bit();
        char get_char();
        unsigned get_int();
        void close();
        bool not_eof() const;
    private:
        char buffer;
        int size;
        std::ifstream in;
    };
    
    std::ifstream::pos_type filesize(const char* filename);
};

#endif	/* HUFFMAN_H */

