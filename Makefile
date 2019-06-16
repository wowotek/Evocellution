CFLAGS	= -W
CLINK	= -lGL -lGLU -lglut
CC		= g++

odir	= bin/o
lib		= src/lib

all: build_folder Evocellution clean

build_folder:
	@echo "Creating Build Folder..."
	@mkdir -p bin/o/

clean:
	rm -rf bin/o
