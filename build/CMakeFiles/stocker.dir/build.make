# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/775/bin/cmake

# The command to remove a file.
RM = /snap/cmake/775/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mac/stocker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mac/stocker/build

# Include any dependencies generated for this target.
include CMakeFiles/stocker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stocker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stocker.dir/flags.make

CMakeFiles/stocker.dir/main.cpp.o: CMakeFiles/stocker.dir/flags.make
CMakeFiles/stocker.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mac/stocker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stocker.dir/main.cpp.o"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stocker.dir/main.cpp.o -c /home/mac/stocker/main.cpp

CMakeFiles/stocker.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stocker.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mac/stocker/main.cpp > CMakeFiles/stocker.dir/main.cpp.i

CMakeFiles/stocker.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stocker.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mac/stocker/main.cpp -o CMakeFiles/stocker.dir/main.cpp.s

# Object files for target stocker
stocker_OBJECTS = \
"CMakeFiles/stocker.dir/main.cpp.o"

# External object files for target stocker
stocker_EXTERNAL_OBJECTS =

stocker: CMakeFiles/stocker.dir/main.cpp.o
stocker: CMakeFiles/stocker.dir/build.make
stocker: CMakeFiles/stocker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mac/stocker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stocker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stocker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stocker.dir/build: stocker

.PHONY : CMakeFiles/stocker.dir/build

CMakeFiles/stocker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stocker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stocker.dir/clean

CMakeFiles/stocker.dir/depend:
	cd /home/mac/stocker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mac/stocker /home/mac/stocker /home/mac/stocker/build /home/mac/stocker/build /home/mac/stocker/build/CMakeFiles/stocker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stocker.dir/depend
