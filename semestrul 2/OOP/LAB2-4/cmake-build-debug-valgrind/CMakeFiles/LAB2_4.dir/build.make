# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Admin/CLionProjects/LAB2-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind

# Include any dependencies generated for this target.
include CMakeFiles/LAB2_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LAB2_4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LAB2_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LAB2_4.dir/flags.make

CMakeFiles/LAB2_4.dir/domain.c.o: CMakeFiles/LAB2_4.dir/flags.make
CMakeFiles/LAB2_4.dir/domain.c.o: /mnt/c/Users/Admin/CLionProjects/LAB2-4/domain.c
CMakeFiles/LAB2_4.dir/domain.c.o: CMakeFiles/LAB2_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LAB2_4.dir/domain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB2_4.dir/domain.c.o -MF CMakeFiles/LAB2_4.dir/domain.c.o.d -o CMakeFiles/LAB2_4.dir/domain.c.o -c /mnt/c/Users/Admin/CLionProjects/LAB2-4/domain.c

CMakeFiles/LAB2_4.dir/domain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LAB2_4.dir/domain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Admin/CLionProjects/LAB2-4/domain.c > CMakeFiles/LAB2_4.dir/domain.c.i

CMakeFiles/LAB2_4.dir/domain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LAB2_4.dir/domain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Admin/CLionProjects/LAB2-4/domain.c -o CMakeFiles/LAB2_4.dir/domain.c.s

CMakeFiles/LAB2_4.dir/ui.c.o: CMakeFiles/LAB2_4.dir/flags.make
CMakeFiles/LAB2_4.dir/ui.c.o: /mnt/c/Users/Admin/CLionProjects/LAB2-4/ui.c
CMakeFiles/LAB2_4.dir/ui.c.o: CMakeFiles/LAB2_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LAB2_4.dir/ui.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB2_4.dir/ui.c.o -MF CMakeFiles/LAB2_4.dir/ui.c.o.d -o CMakeFiles/LAB2_4.dir/ui.c.o -c /mnt/c/Users/Admin/CLionProjects/LAB2-4/ui.c

CMakeFiles/LAB2_4.dir/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LAB2_4.dir/ui.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Admin/CLionProjects/LAB2-4/ui.c > CMakeFiles/LAB2_4.dir/ui.c.i

CMakeFiles/LAB2_4.dir/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LAB2_4.dir/ui.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Admin/CLionProjects/LAB2-4/ui.c -o CMakeFiles/LAB2_4.dir/ui.c.s

CMakeFiles/LAB2_4.dir/main.c.o: CMakeFiles/LAB2_4.dir/flags.make
CMakeFiles/LAB2_4.dir/main.c.o: /mnt/c/Users/Admin/CLionProjects/LAB2-4/main.c
CMakeFiles/LAB2_4.dir/main.c.o: CMakeFiles/LAB2_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/LAB2_4.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB2_4.dir/main.c.o -MF CMakeFiles/LAB2_4.dir/main.c.o.d -o CMakeFiles/LAB2_4.dir/main.c.o -c /mnt/c/Users/Admin/CLionProjects/LAB2-4/main.c

CMakeFiles/LAB2_4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LAB2_4.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Admin/CLionProjects/LAB2-4/main.c > CMakeFiles/LAB2_4.dir/main.c.i

CMakeFiles/LAB2_4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LAB2_4.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Admin/CLionProjects/LAB2-4/main.c -o CMakeFiles/LAB2_4.dir/main.c.s

CMakeFiles/LAB2_4.dir/teste.c.o: CMakeFiles/LAB2_4.dir/flags.make
CMakeFiles/LAB2_4.dir/teste.c.o: /mnt/c/Users/Admin/CLionProjects/LAB2-4/teste.c
CMakeFiles/LAB2_4.dir/teste.c.o: CMakeFiles/LAB2_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/LAB2_4.dir/teste.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LAB2_4.dir/teste.c.o -MF CMakeFiles/LAB2_4.dir/teste.c.o.d -o CMakeFiles/LAB2_4.dir/teste.c.o -c /mnt/c/Users/Admin/CLionProjects/LAB2-4/teste.c

CMakeFiles/LAB2_4.dir/teste.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LAB2_4.dir/teste.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Admin/CLionProjects/LAB2-4/teste.c > CMakeFiles/LAB2_4.dir/teste.c.i

CMakeFiles/LAB2_4.dir/teste.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LAB2_4.dir/teste.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Admin/CLionProjects/LAB2-4/teste.c -o CMakeFiles/LAB2_4.dir/teste.c.s

# Object files for target LAB2_4
LAB2_4_OBJECTS = \
"CMakeFiles/LAB2_4.dir/domain.c.o" \
"CMakeFiles/LAB2_4.dir/ui.c.o" \
"CMakeFiles/LAB2_4.dir/main.c.o" \
"CMakeFiles/LAB2_4.dir/teste.c.o"

# External object files for target LAB2_4
LAB2_4_EXTERNAL_OBJECTS =

LAB2_4: CMakeFiles/LAB2_4.dir/domain.c.o
LAB2_4: CMakeFiles/LAB2_4.dir/ui.c.o
LAB2_4: CMakeFiles/LAB2_4.dir/main.c.o
LAB2_4: CMakeFiles/LAB2_4.dir/teste.c.o
LAB2_4: CMakeFiles/LAB2_4.dir/build.make
LAB2_4: CMakeFiles/LAB2_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable LAB2_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LAB2_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LAB2_4.dir/build: LAB2_4
.PHONY : CMakeFiles/LAB2_4.dir/build

CMakeFiles/LAB2_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LAB2_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LAB2_4.dir/clean

CMakeFiles/LAB2_4.dir/depend:
	cd /mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Admin/CLionProjects/LAB2-4 /mnt/c/Users/Admin/CLionProjects/LAB2-4 /mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind /mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind /mnt/c/Users/Admin/CLionProjects/LAB2-4/cmake-build-debug-valgrind/CMakeFiles/LAB2_4.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/LAB2_4.dir/depend
