# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mihver1/Projects/ifmo/cpp/prakt2/huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mihver1/Projects/ifmo/cpp/prakt2/huffman

# Include any dependencies generated for this target.
include CMakeFiles/libhuffman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libhuffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libhuffman.dir/flags.make

CMakeFiles/libhuffman.dir/huffman.cpp.o: CMakeFiles/libhuffman.dir/flags.make
CMakeFiles/libhuffman.dir/huffman.cpp.o: huffman.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mihver1/Projects/ifmo/cpp/prakt2/huffman/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/libhuffman.dir/huffman.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libhuffman.dir/huffman.cpp.o -c /home/mihver1/Projects/ifmo/cpp/prakt2/huffman/huffman.cpp

CMakeFiles/libhuffman.dir/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libhuffman.dir/huffman.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mihver1/Projects/ifmo/cpp/prakt2/huffman/huffman.cpp > CMakeFiles/libhuffman.dir/huffman.cpp.i

CMakeFiles/libhuffman.dir/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libhuffman.dir/huffman.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mihver1/Projects/ifmo/cpp/prakt2/huffman/huffman.cpp -o CMakeFiles/libhuffman.dir/huffman.cpp.s

CMakeFiles/libhuffman.dir/huffman.cpp.o.requires:
.PHONY : CMakeFiles/libhuffman.dir/huffman.cpp.o.requires

CMakeFiles/libhuffman.dir/huffman.cpp.o.provides: CMakeFiles/libhuffman.dir/huffman.cpp.o.requires
	$(MAKE) -f CMakeFiles/libhuffman.dir/build.make CMakeFiles/libhuffman.dir/huffman.cpp.o.provides.build
.PHONY : CMakeFiles/libhuffman.dir/huffman.cpp.o.provides

CMakeFiles/libhuffman.dir/huffman.cpp.o.provides.build: CMakeFiles/libhuffman.dir/huffman.cpp.o

# Object files for target libhuffman
libhuffman_OBJECTS = \
"CMakeFiles/libhuffman.dir/huffman.cpp.o"

# External object files for target libhuffman
libhuffman_EXTERNAL_OBJECTS =

liblibhuffman.so: CMakeFiles/libhuffman.dir/huffman.cpp.o
liblibhuffman.so: CMakeFiles/libhuffman.dir/build.make
liblibhuffman.so: CMakeFiles/libhuffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library liblibhuffman.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libhuffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libhuffman.dir/build: liblibhuffman.so
.PHONY : CMakeFiles/libhuffman.dir/build

CMakeFiles/libhuffman.dir/requires: CMakeFiles/libhuffman.dir/huffman.cpp.o.requires
.PHONY : CMakeFiles/libhuffman.dir/requires

CMakeFiles/libhuffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libhuffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libhuffman.dir/clean

CMakeFiles/libhuffman.dir/depend:
	cd /home/mihver1/Projects/ifmo/cpp/prakt2/huffman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mihver1/Projects/ifmo/cpp/prakt2/huffman /home/mihver1/Projects/ifmo/cpp/prakt2/huffman /home/mihver1/Projects/ifmo/cpp/prakt2/huffman /home/mihver1/Projects/ifmo/cpp/prakt2/huffman /home/mihver1/Projects/ifmo/cpp/prakt2/huffman/CMakeFiles/libhuffman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libhuffman.dir/depend
