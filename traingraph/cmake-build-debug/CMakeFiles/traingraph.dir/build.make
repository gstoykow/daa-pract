# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/georgi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/georgi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/georgi/CLionProjects/traingraph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/georgi/CLionProjects/traingraph/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/traingraph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/traingraph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/traingraph.dir/flags.make

CMakeFiles/traingraph.dir/main.cpp.o: CMakeFiles/traingraph.dir/flags.make
CMakeFiles/traingraph.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi/CLionProjects/traingraph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/traingraph.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traingraph.dir/main.cpp.o -c /home/georgi/CLionProjects/traingraph/main.cpp

CMakeFiles/traingraph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traingraph.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi/CLionProjects/traingraph/main.cpp > CMakeFiles/traingraph.dir/main.cpp.i

CMakeFiles/traingraph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traingraph.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi/CLionProjects/traingraph/main.cpp -o CMakeFiles/traingraph.dir/main.cpp.s

# Object files for target traingraph
traingraph_OBJECTS = \
"CMakeFiles/traingraph.dir/main.cpp.o"

# External object files for target traingraph
traingraph_EXTERNAL_OBJECTS =

traingraph: CMakeFiles/traingraph.dir/main.cpp.o
traingraph: CMakeFiles/traingraph.dir/build.make
traingraph: CMakeFiles/traingraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/georgi/CLionProjects/traingraph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable traingraph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traingraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/traingraph.dir/build: traingraph

.PHONY : CMakeFiles/traingraph.dir/build

CMakeFiles/traingraph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/traingraph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/traingraph.dir/clean

CMakeFiles/traingraph.dir/depend:
	cd /home/georgi/CLionProjects/traingraph/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/georgi/CLionProjects/traingraph /home/georgi/CLionProjects/traingraph /home/georgi/CLionProjects/traingraph/cmake-build-debug /home/georgi/CLionProjects/traingraph/cmake-build-debug /home/georgi/CLionProjects/traingraph/cmake-build-debug/CMakeFiles/traingraph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/traingraph.dir/depend
