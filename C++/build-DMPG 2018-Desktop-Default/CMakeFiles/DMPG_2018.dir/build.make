# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles JOM" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default"

# Include any dependencies generated for this target.
include CMakeFiles\DMPG_2018.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\DMPG_2018.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\DMPG_2018.dir\flags.make

CMakeFiles\DMPG_2018.dir\main.cpp.obj: CMakeFiles\DMPG_2018.dir\flags.make
CMakeFiles\DMPG_2018.dir\main.cpp.obj: "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018\main.cpp"
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DMPG_2018.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DMPG_2018.dir\main.cpp.obj -c "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018\main.cpp"

CMakeFiles\DMPG_2018.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DMPG_2018.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018\main.cpp" > CMakeFiles\DMPG_2018.dir\main.cpp.i

CMakeFiles\DMPG_2018.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DMPG_2018.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018\main.cpp" -o CMakeFiles\DMPG_2018.dir\main.cpp.s

CMakeFiles\DMPG_2018.dir\main.cpp.obj.requires:

.PHONY : CMakeFiles\DMPG_2018.dir\main.cpp.obj.requires

CMakeFiles\DMPG_2018.dir\main.cpp.obj.provides: CMakeFiles\DMPG_2018.dir\main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\DMPG_2018.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\DMPG_2018.dir\main.cpp.obj.provides.build
.PHONY : CMakeFiles\DMPG_2018.dir\main.cpp.obj.provides

CMakeFiles\DMPG_2018.dir\main.cpp.obj.provides.build: CMakeFiles\DMPG_2018.dir\main.cpp.obj


# Object files for target DMPG_2018
DMPG_2018_OBJECTS = \
"CMakeFiles\DMPG_2018.dir\main.cpp.obj"

# External object files for target DMPG_2018
DMPG_2018_EXTERNAL_OBJECTS =

DMPG_2018.exe: CMakeFiles\DMPG_2018.dir\main.cpp.obj
DMPG_2018.exe: CMakeFiles\DMPG_2018.dir\build.make
DMPG_2018.exe: CMakeFiles\DMPG_2018.dir\linklibs.rsp
DMPG_2018.exe: CMakeFiles\DMPG_2018.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DMPG_2018.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E remove -f CMakeFiles\DMPG_2018.dir/objects.a
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\ar.exe cr CMakeFiles\DMPG_2018.dir/objects.a @CMakeFiles\DMPG_2018.dir\objects1.rsp
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE    -Wl,--whole-archive CMakeFiles\DMPG_2018.dir/objects.a -Wl,--no-whole-archive  -o DMPG_2018.exe -Wl,--out-implib,libDMPG_2018.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles\DMPG_2018.dir\linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles\DMPG_2018.dir\build: DMPG_2018.exe

.PHONY : CMakeFiles\DMPG_2018.dir\build

CMakeFiles\DMPG_2018.dir\requires: CMakeFiles\DMPG_2018.dir\main.cpp.obj.requires

.PHONY : CMakeFiles\DMPG_2018.dir\requires

CMakeFiles\DMPG_2018.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DMPG_2018.dir\cmake_clean.cmake
.PHONY : CMakeFiles\DMPG_2018.dir\clean

CMakeFiles\DMPG_2018.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles JOM" "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018" "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\DMPG 2018" "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default" "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default" "C:\Users\aisae\Documents\Sourcetree\Challenges\C++\build-DMPG 2018-Desktop-Default\CMakeFiles\DMPG_2018.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\DMPG_2018.dir\depend

