# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files (x86)\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files (x86)\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitHub\HeartStoneCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\HeartStoneCalculator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HeartStoneCalculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HeartStoneCalculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HeartStoneCalculator.dir/flags.make

CMakeFiles/HeartStoneCalculator.dir/main.cpp.obj: CMakeFiles/HeartStoneCalculator.dir/flags.make
CMakeFiles/HeartStoneCalculator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\HeartStoneCalculator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HeartStoneCalculator.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HeartStoneCalculator.dir\main.cpp.obj -c D:\GitHub\HeartStoneCalculator\main.cpp

CMakeFiles/HeartStoneCalculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HeartStoneCalculator.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\HeartStoneCalculator\main.cpp > CMakeFiles\HeartStoneCalculator.dir\main.cpp.i

CMakeFiles/HeartStoneCalculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HeartStoneCalculator.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\GitHub\HeartStoneCalculator\main.cpp -o CMakeFiles\HeartStoneCalculator.dir\main.cpp.s

# Object files for target HeartStoneCalculator
HeartStoneCalculator_OBJECTS = \
"CMakeFiles/HeartStoneCalculator.dir/main.cpp.obj"

# External object files for target HeartStoneCalculator
HeartStoneCalculator_EXTERNAL_OBJECTS =

HeartStoneCalculator.exe: CMakeFiles/HeartStoneCalculator.dir/main.cpp.obj
HeartStoneCalculator.exe: CMakeFiles/HeartStoneCalculator.dir/build.make
HeartStoneCalculator.exe: CMakeFiles/HeartStoneCalculator.dir/linklibs.rsp
HeartStoneCalculator.exe: CMakeFiles/HeartStoneCalculator.dir/objects1.rsp
HeartStoneCalculator.exe: CMakeFiles/HeartStoneCalculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\HeartStoneCalculator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HeartStoneCalculator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HeartStoneCalculator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HeartStoneCalculator.dir/build: HeartStoneCalculator.exe

.PHONY : CMakeFiles/HeartStoneCalculator.dir/build

CMakeFiles/HeartStoneCalculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HeartStoneCalculator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HeartStoneCalculator.dir/clean

CMakeFiles/HeartStoneCalculator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitHub\HeartStoneCalculator D:\GitHub\HeartStoneCalculator D:\GitHub\HeartStoneCalculator\cmake-build-debug D:\GitHub\HeartStoneCalculator\cmake-build-debug D:\GitHub\HeartStoneCalculator\cmake-build-debug\CMakeFiles\HeartStoneCalculator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HeartStoneCalculator.dir/depend
