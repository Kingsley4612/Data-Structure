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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kingsley/CLionProjects/untitled17

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kingsley/CLionProjects/untitled17/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled17.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled17.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled17.dir/flags.make

CMakeFiles/untitled17.dir/main.c.o: CMakeFiles/untitled17.dir/flags.make
CMakeFiles/untitled17.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kingsley/CLionProjects/untitled17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled17.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled17.dir/main.c.o   -c /Users/kingsley/CLionProjects/untitled17/main.c

CMakeFiles/untitled17.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled17.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kingsley/CLionProjects/untitled17/main.c > CMakeFiles/untitled17.dir/main.c.i

CMakeFiles/untitled17.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled17.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kingsley/CLionProjects/untitled17/main.c -o CMakeFiles/untitled17.dir/main.c.s

CMakeFiles/untitled17.dir/init.c.o: CMakeFiles/untitled17.dir/flags.make
CMakeFiles/untitled17.dir/init.c.o: ../init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kingsley/CLionProjects/untitled17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled17.dir/init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled17.dir/init.c.o   -c /Users/kingsley/CLionProjects/untitled17/init.c

CMakeFiles/untitled17.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled17.dir/init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kingsley/CLionProjects/untitled17/init.c > CMakeFiles/untitled17.dir/init.c.i

CMakeFiles/untitled17.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled17.dir/init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kingsley/CLionProjects/untitled17/init.c -o CMakeFiles/untitled17.dir/init.c.s

CMakeFiles/untitled17.dir/foreach.c.o: CMakeFiles/untitled17.dir/flags.make
CMakeFiles/untitled17.dir/foreach.c.o: ../foreach.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kingsley/CLionProjects/untitled17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled17.dir/foreach.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled17.dir/foreach.c.o   -c /Users/kingsley/CLionProjects/untitled17/foreach.c

CMakeFiles/untitled17.dir/foreach.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled17.dir/foreach.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kingsley/CLionProjects/untitled17/foreach.c > CMakeFiles/untitled17.dir/foreach.c.i

CMakeFiles/untitled17.dir/foreach.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled17.dir/foreach.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kingsley/CLionProjects/untitled17/foreach.c -o CMakeFiles/untitled17.dir/foreach.c.s

# Object files for target untitled17
untitled17_OBJECTS = \
"CMakeFiles/untitled17.dir/main.c.o" \
"CMakeFiles/untitled17.dir/init.c.o" \
"CMakeFiles/untitled17.dir/foreach.c.o"

# External object files for target untitled17
untitled17_EXTERNAL_OBJECTS =

untitled17: CMakeFiles/untitled17.dir/main.c.o
untitled17: CMakeFiles/untitled17.dir/init.c.o
untitled17: CMakeFiles/untitled17.dir/foreach.c.o
untitled17: CMakeFiles/untitled17.dir/build.make
untitled17: CMakeFiles/untitled17.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kingsley/CLionProjects/untitled17/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable untitled17"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled17.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled17.dir/build: untitled17

.PHONY : CMakeFiles/untitled17.dir/build

CMakeFiles/untitled17.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled17.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled17.dir/clean

CMakeFiles/untitled17.dir/depend:
	cd /Users/kingsley/CLionProjects/untitled17/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kingsley/CLionProjects/untitled17 /Users/kingsley/CLionProjects/untitled17 /Users/kingsley/CLionProjects/untitled17/cmake-build-debug /Users/kingsley/CLionProjects/untitled17/cmake-build-debug /Users/kingsley/CLionProjects/untitled17/cmake-build-debug/CMakeFiles/untitled17.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled17.dir/depend
