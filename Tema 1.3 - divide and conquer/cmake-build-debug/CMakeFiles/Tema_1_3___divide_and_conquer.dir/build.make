# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Installed games and programs\C++\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Installed games and programs\C++\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tema_1_3___divide_and_conquer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tema_1_3___divide_and_conquer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tema_1_3___divide_and_conquer.dir/flags.make

CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.obj: CMakeFiles/Tema_1_3___divide_and_conquer.dir/flags.make
CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.obj"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tema_1_3___divide_and_conquer.dir\main.cpp.obj -c "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\main.cpp"

CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.i"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\main.cpp" > CMakeFiles\Tema_1_3___divide_and_conquer.dir\main.cpp.i

CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.s"
	"D:\Installed games and programs\C++\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\main.cpp" -o CMakeFiles\Tema_1_3___divide_and_conquer.dir\main.cpp.s

# Object files for target Tema_1_3___divide_and_conquer
Tema_1_3___divide_and_conquer_OBJECTS = \
"CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.obj"

# External object files for target Tema_1_3___divide_and_conquer
Tema_1_3___divide_and_conquer_EXTERNAL_OBJECTS =

Tema_1_3___divide_and_conquer.exe: CMakeFiles/Tema_1_3___divide_and_conquer.dir/main.cpp.obj
Tema_1_3___divide_and_conquer.exe: CMakeFiles/Tema_1_3___divide_and_conquer.dir/build.make
Tema_1_3___divide_and_conquer.exe: CMakeFiles/Tema_1_3___divide_and_conquer.dir/linklibs.rsp
Tema_1_3___divide_and_conquer.exe: CMakeFiles/Tema_1_3___divide_and_conquer.dir/objects1.rsp
Tema_1_3___divide_and_conquer.exe: CMakeFiles/Tema_1_3___divide_and_conquer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tema_1_3___divide_and_conquer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tema_1_3___divide_and_conquer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tema_1_3___divide_and_conquer.dir/build: Tema_1_3___divide_and_conquer.exe

.PHONY : CMakeFiles/Tema_1_3___divide_and_conquer.dir/build

CMakeFiles/Tema_1_3___divide_and_conquer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tema_1_3___divide_and_conquer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tema_1_3___divide_and_conquer.dir/clean

CMakeFiles/Tema_1_3___divide_and_conquer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer" "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer" "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug" "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug" "D:\Dino\Programiranje\Cpp\Strukture podataka i algoritmi\Projekti\Prvi\Tema 1.3 - divide and conquer\cmake-build-debug\CMakeFiles\Tema_1_3___divide_and_conquer.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tema_1_3___divide_and_conquer.dir/depend

