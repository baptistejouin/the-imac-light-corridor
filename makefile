GCC		= g++
CFLAGS	= -Wall -O3 -g
# LDFLAGS	= -lglfw -lGLU -lGL -lm
LIBDIR = -L/System/Library/Frameworks -lglfw -framework Cocoa -framework OpenGL -framework IOKit

BIN_DIR	= bin
INC_DIR = -I include
SRC_DIR	= src
OBJ_DIR	= obj


SRC_FILES 	= $(shell find $(SRC_DIR)/ -type f -name '*.cpp')
OBJ_FILES 	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRC_FILES))
EXEC_BIN	= exec.out


all : build

run : build
	./bin/exec.out

build : $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)/
	$(GCC) -o $(BIN_DIR)/$(EXEC_BIN) $(OBJ_FILES) $(LIBDIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p "$(@D)"
	$(GCC) -c $< -o $@ $(CFLAGS) $(INC_DIR)

clean :
	rm -rf *~
	rm -rf $(SRC_DIR)/*/*~
	rm -rf $(OBJ_DIR)/
	rm -rf $(BIN_DIR)/*
