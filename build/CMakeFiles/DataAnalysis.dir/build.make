# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build

# Include any dependencies generated for this target.
include CMakeFiles/DataAnalysis.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DataAnalysis.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DataAnalysis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataAnalysis.dir/flags.make

CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o: CMakeFiles/DataAnalysis.dir/flags.make
CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o: /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/src/main/main.cpp
CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o: CMakeFiles/DataAnalysis.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o -MF CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o.d -o CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o -c /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/src/main/main.cpp

CMakeFiles/DataAnalysis.dir/src/main/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DataAnalysis.dir/src/main/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/src/main/main.cpp > CMakeFiles/DataAnalysis.dir/src/main/main.cpp.i

CMakeFiles/DataAnalysis.dir/src/main/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DataAnalysis.dir/src/main/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/src/main/main.cpp -o CMakeFiles/DataAnalysis.dir/src/main/main.cpp.s

# Object files for target DataAnalysis
DataAnalysis_OBJECTS = \
"CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o"

# External object files for target DataAnalysis
DataAnalysis_EXTERNAL_OBJECTS =

DataAnalysis: CMakeFiles/DataAnalysis.dir/src/main/main.cpp.o
DataAnalysis: CMakeFiles/DataAnalysis.dir/build.make
DataAnalysis: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.83.0
DataAnalysis: CMakeFiles/DataAnalysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataAnalysis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataAnalysis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataAnalysis.dir/build: DataAnalysis
.PHONY : CMakeFiles/DataAnalysis.dir/build

CMakeFiles/DataAnalysis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataAnalysis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataAnalysis.dir/clean

CMakeFiles/DataAnalysis.dir/depend:
	cd /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build /home/liam/Desktop/Development/IntrotoProgramming/DataAnalysis_IntrotoProgramming/build/CMakeFiles/DataAnalysis.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DataAnalysis.dir/depend

