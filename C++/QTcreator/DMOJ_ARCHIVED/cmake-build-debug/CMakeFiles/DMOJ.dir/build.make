# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /cygdrive/c/Users/aisae/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/aisae/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DMOJ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DMOJ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DMOJ.dir/flags.make

CMakeFiles/DMOJ.dir/completed.cpp.o: CMakeFiles/DMOJ.dir/flags.make
CMakeFiles/DMOJ.dir/completed.cpp.o: ../completed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DMOJ.dir/completed.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DMOJ.dir/completed.cpp.o -c /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/completed.cpp

CMakeFiles/DMOJ.dir/completed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMOJ.dir/completed.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/completed.cpp > CMakeFiles/DMOJ.dir/completed.cpp.i

CMakeFiles/DMOJ.dir/completed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMOJ.dir/completed.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/completed.cpp -o CMakeFiles/DMOJ.dir/completed.cpp.s

CMakeFiles/DMOJ.dir/completed.cpp.o.requires:

.PHONY : CMakeFiles/DMOJ.dir/completed.cpp.o.requires

CMakeFiles/DMOJ.dir/completed.cpp.o.provides: CMakeFiles/DMOJ.dir/completed.cpp.o.requires
	$(MAKE) -f CMakeFiles/DMOJ.dir/build.make CMakeFiles/DMOJ.dir/completed.cpp.o.provides.build
.PHONY : CMakeFiles/DMOJ.dir/completed.cpp.o.provides

CMakeFiles/DMOJ.dir/completed.cpp.o.provides.build: CMakeFiles/DMOJ.dir/completed.cpp.o


CMakeFiles/DMOJ.dir/main.cpp.o: CMakeFiles/DMOJ.dir/flags.make
CMakeFiles/DMOJ.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DMOJ.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DMOJ.dir/main.cpp.o -c /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/main.cpp

CMakeFiles/DMOJ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMOJ.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/main.cpp > CMakeFiles/DMOJ.dir/main.cpp.i

CMakeFiles/DMOJ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMOJ.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/main.cpp -o CMakeFiles/DMOJ.dir/main.cpp.s

CMakeFiles/DMOJ.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DMOJ.dir/main.cpp.o.requires

CMakeFiles/DMOJ.dir/main.cpp.o.provides: CMakeFiles/DMOJ.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DMOJ.dir/build.make CMakeFiles/DMOJ.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DMOJ.dir/main.cpp.o.provides

CMakeFiles/DMOJ.dir/main.cpp.o.provides.build: CMakeFiles/DMOJ.dir/main.cpp.o


CMakeFiles/DMOJ.dir/wip.cpp.o: CMakeFiles/DMOJ.dir/flags.make
CMakeFiles/DMOJ.dir/wip.cpp.o: ../wip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DMOJ.dir/wip.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DMOJ.dir/wip.cpp.o -c /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/wip.cpp

CMakeFiles/DMOJ.dir/wip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMOJ.dir/wip.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/wip.cpp > CMakeFiles/DMOJ.dir/wip.cpp.i

CMakeFiles/DMOJ.dir/wip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMOJ.dir/wip.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/wip.cpp -o CMakeFiles/DMOJ.dir/wip.cpp.s

CMakeFiles/DMOJ.dir/wip.cpp.o.requires:

.PHONY : CMakeFiles/DMOJ.dir/wip.cpp.o.requires

CMakeFiles/DMOJ.dir/wip.cpp.o.provides: CMakeFiles/DMOJ.dir/wip.cpp.o.requires
	$(MAKE) -f CMakeFiles/DMOJ.dir/build.make CMakeFiles/DMOJ.dir/wip.cpp.o.provides.build
.PHONY : CMakeFiles/DMOJ.dir/wip.cpp.o.provides

CMakeFiles/DMOJ.dir/wip.cpp.o.provides.build: CMakeFiles/DMOJ.dir/wip.cpp.o


# Object files for target DMOJ
DMOJ_OBJECTS = \
"CMakeFiles/DMOJ.dir/completed.cpp.o" \
"CMakeFiles/DMOJ.dir/main.cpp.o" \
"CMakeFiles/DMOJ.dir/wip.cpp.o"

# External object files for target DMOJ
DMOJ_EXTERNAL_OBJECTS =

DMOJ.exe: CMakeFiles/DMOJ.dir/completed.cpp.o
DMOJ.exe: CMakeFiles/DMOJ.dir/main.cpp.o
DMOJ.exe: CMakeFiles/DMOJ.dir/wip.cpp.o
DMOJ.exe: CMakeFiles/DMOJ.dir/build.make
DMOJ.exe: CMakeFiles/DMOJ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DMOJ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DMOJ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DMOJ.dir/build: DMOJ.exe

.PHONY : CMakeFiles/DMOJ.dir/build

CMakeFiles/DMOJ.dir/requires: CMakeFiles/DMOJ.dir/completed.cpp.o.requires
CMakeFiles/DMOJ.dir/requires: CMakeFiles/DMOJ.dir/main.cpp.o.requires
CMakeFiles/DMOJ.dir/requires: CMakeFiles/DMOJ.dir/wip.cpp.o.requires

.PHONY : CMakeFiles/DMOJ.dir/requires

CMakeFiles/DMOJ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DMOJ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DMOJ.dir/clean

CMakeFiles/DMOJ.dir/depend:
	cd /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug /cygdrive/c/Users/aisae/Documents/Sourcetree/Challenges/C++/QTcreator/DMOJ/cmake-build-debug/CMakeFiles/DMOJ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DMOJ.dir/depend

