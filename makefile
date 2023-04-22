GCC		= g++
CFLAGS	= -Wall -O3 -g
LIBDIR	= -lglfw -lGLU -lGL -lm
# LIBDIR = -L/System/Library/Frameworks -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/baptiste/workflow/the-imac-light-corridor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/baptiste/workflow/the-imac-light-corridor

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.25.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.25.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/baptiste/workflow/the-imac-light-corridor/CMakeFiles /Users/baptiste/workflow/the-imac-light-corridor//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/baptiste/workflow/the-imac-light-corridor/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named imac_light_corridor

# Build rule for target.
imac_light_corridor: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 imac_light_corridor
.PHONY : imac_light_corridor

# fast build rule for target.
imac_light_corridor/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/build
.PHONY : imac_light_corridor/fast

src/3D_tools.o: src/3D_tools.cpp.o
.PHONY : src/3D_tools.o

# target to build an object file
src/3D_tools.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/3D_tools.cpp.o
.PHONY : src/3D_tools.cpp.o

src/3D_tools.i: src/3D_tools.cpp.i
.PHONY : src/3D_tools.i

# target to preprocess a source file
src/3D_tools.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/3D_tools.cpp.i
.PHONY : src/3D_tools.cpp.i

src/3D_tools.s: src/3D_tools.cpp.s
.PHONY : src/3D_tools.s

# target to generate assembly for a file
src/3D_tools.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/3D_tools.cpp.s
.PHONY : src/3D_tools.cpp.s

src/draw_scene.o: src/draw_scene.cpp.o
.PHONY : src/draw_scene.o

# target to build an object file
src/draw_scene.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/draw_scene.cpp.o
.PHONY : src/draw_scene.cpp.o

src/draw_scene.i: src/draw_scene.cpp.i
.PHONY : src/draw_scene.i

# target to preprocess a source file
src/draw_scene.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/draw_scene.cpp.i
.PHONY : src/draw_scene.cpp.i

src/draw_scene.s: src/draw_scene.cpp.s
.PHONY : src/draw_scene.s

# target to generate assembly for a file
src/draw_scene.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/draw_scene.cpp.s
.PHONY : src/draw_scene.cpp.s

src/geometry.o: src/geometry.cpp.o
.PHONY : src/geometry.o

# target to build an object file
src/geometry.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/geometry.cpp.o
.PHONY : src/geometry.cpp.o

src/geometry.i: src/geometry.cpp.i
.PHONY : src/geometry.i

# target to preprocess a source file
src/geometry.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/geometry.cpp.i
.PHONY : src/geometry.cpp.i

src/geometry.s: src/geometry.cpp.s
.PHONY : src/geometry.s

# target to generate assembly for a file
src/geometry.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/geometry.cpp.s
.PHONY : src/geometry.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/imac_light_corridor.dir/build.make CMakeFiles/imac_light_corridor.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... imac_light_corridor"
	@echo "... src/3D_tools.o"
	@echo "... src/3D_tools.i"
	@echo "... src/3D_tools.s"
	@echo "... src/draw_scene.o"
	@echo "... src/draw_scene.i"
	@echo "... src/draw_scene.s"
	@echo "... src/geometry.o"
	@echo "... src/geometry.i"
	@echo "... src/geometry.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

