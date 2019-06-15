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

wlib.o: ${lib}/wowotek/glHelper.hpp ${lib}/wowotek/type.hpp ${lib}/wowotek/glHelper.cpp 
	${CC} ${CFLAGS} -c ${lib}/wowotek/glHelper.cpp -o ${odir}/wlib.o

# --------------

control.o: wlib.o src/game/control.hpp src/game/control.cpp
	${CC} ${CFLAGS} -c src/game/control.cpp -o ${odir}/control.o

render.o: wlib.o src/game/render.hpp src/game/render.cpp
	${CC} ${CFLAGS} -c src/game/render.cpp -o ${odir}/render.o

game.o: wlib.o control.o render.o
	ld -r ${odir}/wlib.o ${odir}/control.o ${odir}/render.o -o ${odir}/game.o
	rm ${odir}/control.o ${odir}/render.o

# ---------------

entity.o: src/entities/objects.hpp src/entities/entity.cpp
	${CC} ${CFLAGS} -c src/entities/entity.cpp -o ${odir}/entity.o

cell.o: src/entities/objects.hpp src/entities/cell.cpp
	${CC} ${CFLAGS} -c src/entities/cell.cpp -o ${odir}/cell.o

entities.o: entity.o cell.o
	ld -r ${odir}/cell.o ${odir}/entity.o -o ${odir}/entities.o
	rm ${odir}/cell.o ${odir}/entity.o

# ------------------

objects.o: game.o entities.o wlib.o
	ld -r ${odir}/game.o ${odir}/entities.o -o ${odir}/objects.o
	rm ${odir}/game.o ${odir}/entities.o ${odir}/wlib.o

# ------------------
main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o ${odir}/main.o

# ------------------

Evocellution: objects.o main.o 
	${CC} ${CFLAGS} ${odir}/main.o ${odir}/objects.o ${CLINK} -o bin/Evocellution
