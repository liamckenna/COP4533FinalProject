# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/COP4533FinalProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/COP4533FinalProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/COP4533FinalProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COP4533FinalProject.dir/flags.make

CMakeFiles/COP4533FinalProject.dir/main.cpp.obj: CMakeFiles/COP4533FinalProject.dir/flags.make
CMakeFiles/COP4533FinalProject.dir/main.cpp.obj: ../main.cpp
CMakeFiles/COP4533FinalProject.dir/main.cpp.obj: CMakeFiles/COP4533FinalProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COP4533FinalProject.dir/main.cpp.obj"
	C:\PROGRA~2\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/COP4533FinalProject.dir/main.cpp.obj -MF CMakeFiles\COP4533FinalProject.dir\main.cpp.obj.d -o CMakeFiles\COP4533FinalProject.dir\main.cpp.obj -c C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\main.cpp

CMakeFiles/COP4533FinalProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COP4533FinalProject.dir/main.cpp.i"
	C:\PROGRA~2\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\main.cpp > CMakeFiles\COP4533FinalProject.dir\main.cpp.i

CMakeFiles/COP4533FinalProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COP4533FinalProject.dir/main.cpp.s"
	C:\PROGRA~2\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\main.cpp -o CMakeFiles\COP4533FinalProject.dir\main.cpp.s

# Object files for target COP4533FinalProject
COP4533FinalProject_OBJECTS = \
"CMakeFiles/COP4533FinalProject.dir/main.cpp.obj"

# External object files for target COP4533FinalProject
COP4533FinalProject_EXTERNAL_OBJECTS =

COP4533FinalProject.exe: CMakeFiles/COP4533FinalProject.dir/main.cpp.obj
COP4533FinalProject.exe: CMakeFiles/COP4533FinalProject.dir/build.make
COP4533FinalProject.exe: CMakeFiles/COP4533FinalProject.dir/linklibs.rsp
COP4533FinalProject.exe: CMakeFiles/COP4533FinalProject.dir/objects1.rsp
COP4533FinalProject.exe: CMakeFiles/COP4533FinalProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COP4533FinalProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COP4533FinalProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COP4533FinalProject.dir/build: COP4533FinalProject.exe
.PHONY : CMakeFiles/COP4533FinalProject.dir/build

CMakeFiles/COP4533FinalProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COP4533FinalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COP4533FinalProject.dir/clean

CMakeFiles/COP4533FinalProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug C:\Users\erika\Desktop\Fall23\COP4533\COP4533FinalProject\cmake-build-debug\CMakeFiles\COP4533FinalProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COP4533FinalProject.dir/depend

