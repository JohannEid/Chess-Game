# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/johann/Documents/Computerscience/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/johann/Documents/Computerscience/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johann/Work/Chess_graphique

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johann/Work/Chess_graphique/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Chess_Game_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chess_Game_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chess_Game_.dir/flags.make

CMakeFiles/Chess_Game_.dir/main.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chess_Game_.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/main.cpp.o -c /home/johann/Work/Chess_graphique/main.cpp

CMakeFiles/Chess_Game_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/main.cpp > CMakeFiles/Chess_Game_.dir/main.cpp.i

CMakeFiles/Chess_Game_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/main.cpp -o CMakeFiles/Chess_Game_.dir/main.cpp.s

CMakeFiles/Chess_Game_.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/main.cpp.o.requires

CMakeFiles/Chess_Game_.dir/main.cpp.o.provides: CMakeFiles/Chess_Game_.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/main.cpp.o.provides

CMakeFiles/Chess_Game_.dir/main.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/main.cpp.o


CMakeFiles/Chess_Game_.dir/object.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/object.cpp.o: ../object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Chess_Game_.dir/object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/object.cpp.o -c /home/johann/Work/Chess_graphique/object.cpp

CMakeFiles/Chess_Game_.dir/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/object.cpp > CMakeFiles/Chess_Game_.dir/object.cpp.i

CMakeFiles/Chess_Game_.dir/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/object.cpp -o CMakeFiles/Chess_Game_.dir/object.cpp.s

CMakeFiles/Chess_Game_.dir/object.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/object.cpp.o.requires

CMakeFiles/Chess_Game_.dir/object.cpp.o.provides: CMakeFiles/Chess_Game_.dir/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/object.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/object.cpp.o.provides

CMakeFiles/Chess_Game_.dir/object.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/object.cpp.o


CMakeFiles/Chess_Game_.dir/Board.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/Board.cpp.o: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Chess_Game_.dir/Board.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/Board.cpp.o -c /home/johann/Work/Chess_graphique/Board.cpp

CMakeFiles/Chess_Game_.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/Board.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/Board.cpp > CMakeFiles/Chess_Game_.dir/Board.cpp.i

CMakeFiles/Chess_Game_.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/Board.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/Board.cpp -o CMakeFiles/Chess_Game_.dir/Board.cpp.s

CMakeFiles/Chess_Game_.dir/Board.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/Board.cpp.o.requires

CMakeFiles/Chess_Game_.dir/Board.cpp.o.provides: CMakeFiles/Chess_Game_.dir/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/Board.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/Board.cpp.o.provides

CMakeFiles/Chess_Game_.dir/Board.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/Board.cpp.o


CMakeFiles/Chess_Game_.dir/Player.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Chess_Game_.dir/Player.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/Player.cpp.o -c /home/johann/Work/Chess_graphique/Player.cpp

CMakeFiles/Chess_Game_.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/Player.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/Player.cpp > CMakeFiles/Chess_Game_.dir/Player.cpp.i

CMakeFiles/Chess_Game_.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/Player.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/Player.cpp -o CMakeFiles/Chess_Game_.dir/Player.cpp.s

CMakeFiles/Chess_Game_.dir/Player.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/Player.cpp.o.requires

CMakeFiles/Chess_Game_.dir/Player.cpp.o.provides: CMakeFiles/Chess_Game_.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/Player.cpp.o.provides

CMakeFiles/Chess_Game_.dir/Player.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/Player.cpp.o


CMakeFiles/Chess_Game_.dir/common.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/common.cpp.o: ../common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Chess_Game_.dir/common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/common.cpp.o -c /home/johann/Work/Chess_graphique/common.cpp

CMakeFiles/Chess_Game_.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/common.cpp > CMakeFiles/Chess_Game_.dir/common.cpp.i

CMakeFiles/Chess_Game_.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/common.cpp -o CMakeFiles/Chess_Game_.dir/common.cpp.s

CMakeFiles/Chess_Game_.dir/common.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/common.cpp.o.requires

CMakeFiles/Chess_Game_.dir/common.cpp.o.provides: CMakeFiles/Chess_Game_.dir/common.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/common.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/common.cpp.o.provides

CMakeFiles/Chess_Game_.dir/common.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/common.cpp.o


CMakeFiles/Chess_Game_.dir/engine.cpp.o: CMakeFiles/Chess_Game_.dir/flags.make
CMakeFiles/Chess_Game_.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Chess_Game_.dir/engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Chess_Game_.dir/engine.cpp.o -c /home/johann/Work/Chess_graphique/engine.cpp

CMakeFiles/Chess_Game_.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chess_Game_.dir/engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/johann/Work/Chess_graphique/engine.cpp > CMakeFiles/Chess_Game_.dir/engine.cpp.i

CMakeFiles/Chess_Game_.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chess_Game_.dir/engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/johann/Work/Chess_graphique/engine.cpp -o CMakeFiles/Chess_Game_.dir/engine.cpp.s

CMakeFiles/Chess_Game_.dir/engine.cpp.o.requires:

.PHONY : CMakeFiles/Chess_Game_.dir/engine.cpp.o.requires

CMakeFiles/Chess_Game_.dir/engine.cpp.o.provides: CMakeFiles/Chess_Game_.dir/engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/Chess_Game_.dir/build.make CMakeFiles/Chess_Game_.dir/engine.cpp.o.provides.build
.PHONY : CMakeFiles/Chess_Game_.dir/engine.cpp.o.provides

CMakeFiles/Chess_Game_.dir/engine.cpp.o.provides.build: CMakeFiles/Chess_Game_.dir/engine.cpp.o


# Object files for target Chess_Game_
Chess_Game__OBJECTS = \
"CMakeFiles/Chess_Game_.dir/main.cpp.o" \
"CMakeFiles/Chess_Game_.dir/object.cpp.o" \
"CMakeFiles/Chess_Game_.dir/Board.cpp.o" \
"CMakeFiles/Chess_Game_.dir/Player.cpp.o" \
"CMakeFiles/Chess_Game_.dir/common.cpp.o" \
"CMakeFiles/Chess_Game_.dir/engine.cpp.o"

# External object files for target Chess_Game_
Chess_Game__EXTERNAL_OBJECTS =

Chess_Game_: CMakeFiles/Chess_Game_.dir/main.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/object.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/Board.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/Player.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/common.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/engine.cpp.o
Chess_Game_: CMakeFiles/Chess_Game_.dir/build.make
Chess_Game_: /usr/lib/x86_64-linux-gnu/libsfml-system.so
Chess_Game_: /usr/lib/x86_64-linux-gnu/libsfml-window.so
Chess_Game_: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
Chess_Game_: /usr/lib/x86_64-linux-gnu/libsfml-network.so
Chess_Game_: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
Chess_Game_: CMakeFiles/Chess_Game_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Chess_Game_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Chess_Game_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chess_Game_.dir/build: Chess_Game_

.PHONY : CMakeFiles/Chess_Game_.dir/build

CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/main.cpp.o.requires
CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/object.cpp.o.requires
CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/Board.cpp.o.requires
CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/Player.cpp.o.requires
CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/common.cpp.o.requires
CMakeFiles/Chess_Game_.dir/requires: CMakeFiles/Chess_Game_.dir/engine.cpp.o.requires

.PHONY : CMakeFiles/Chess_Game_.dir/requires

CMakeFiles/Chess_Game_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Chess_Game_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Chess_Game_.dir/clean

CMakeFiles/Chess_Game_.dir/depend:
	cd /home/johann/Work/Chess_graphique/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johann/Work/Chess_graphique /home/johann/Work/Chess_graphique /home/johann/Work/Chess_graphique/cmake-build-debug /home/johann/Work/Chess_graphique/cmake-build-debug /home/johann/Work/Chess_graphique/cmake-build-debug/CMakeFiles/Chess_Game_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Chess_Game_.dir/depend

