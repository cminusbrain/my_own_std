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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/username/projects/my_own_std

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/username/projects/my_own_std/build

# Include any dependencies generated for this target.
include applications/server/CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include applications/server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include applications/server/CMakeFiles/server.dir/flags.make

applications/server/CMakeFiles/server.dir/main.cpp.o: applications/server/CMakeFiles/server.dir/flags.make
applications/server/CMakeFiles/server.dir/main.cpp.o: ../applications/server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/username/projects/my_own_std/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object applications/server/CMakeFiles/server.dir/main.cpp.o"
	cd /home/username/projects/my_own_std/build/applications/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server.dir/main.cpp.o -c /home/username/projects/my_own_std/applications/server/main.cpp

applications/server/CMakeFiles/server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/main.cpp.i"
	cd /home/username/projects/my_own_std/build/applications/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/username/projects/my_own_std/applications/server/main.cpp > CMakeFiles/server.dir/main.cpp.i

applications/server/CMakeFiles/server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/main.cpp.s"
	cd /home/username/projects/my_own_std/build/applications/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/username/projects/my_own_std/applications/server/main.cpp -o CMakeFiles/server.dir/main.cpp.s

applications/server/CMakeFiles/server.dir/main.cpp.o.requires:

.PHONY : applications/server/CMakeFiles/server.dir/main.cpp.o.requires

applications/server/CMakeFiles/server.dir/main.cpp.o.provides: applications/server/CMakeFiles/server.dir/main.cpp.o.requires
	$(MAKE) -f applications/server/CMakeFiles/server.dir/build.make applications/server/CMakeFiles/server.dir/main.cpp.o.provides.build
.PHONY : applications/server/CMakeFiles/server.dir/main.cpp.o.provides

applications/server/CMakeFiles/server.dir/main.cpp.o.provides.build: applications/server/CMakeFiles/server.dir/main.cpp.o


# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/main.cpp.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

applications/server/server: applications/server/CMakeFiles/server.dir/main.cpp.o
applications/server/server: applications/server/CMakeFiles/server.dir/build.make
applications/server/server: transport/src/libtransport.a
applications/server/server: transport/socket/libsocket.a
applications/server/server: applications/server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/username/projects/my_own_std/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable server"
	cd /home/username/projects/my_own_std/build/applications/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
applications/server/CMakeFiles/server.dir/build: applications/server/server

.PHONY : applications/server/CMakeFiles/server.dir/build

applications/server/CMakeFiles/server.dir/requires: applications/server/CMakeFiles/server.dir/main.cpp.o.requires

.PHONY : applications/server/CMakeFiles/server.dir/requires

applications/server/CMakeFiles/server.dir/clean:
	cd /home/username/projects/my_own_std/build/applications/server && $(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : applications/server/CMakeFiles/server.dir/clean

applications/server/CMakeFiles/server.dir/depend:
	cd /home/username/projects/my_own_std/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/username/projects/my_own_std /home/username/projects/my_own_std/applications/server /home/username/projects/my_own_std/build /home/username/projects/my_own_std/build/applications/server /home/username/projects/my_own_std/build/applications/server/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : applications/server/CMakeFiles/server.dir/depend
