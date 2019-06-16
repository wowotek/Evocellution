CFLAGS	= -W
CLINK	= -lGL -lGLU -lglut
CC		= g++

odir	= bin/o
lib		= src/lib

all: clean build_folder Evocellution

build_folder:
	@echo "Creating Build Folder..."
	@mkdir -p bin/o/

clean:
	@echo "Cleaning Objects Files..."
	@rm -rf bin/o

# src/lib/wowotek/
wlib.o: ${lib}/wowotek/glHelper.cpp ${lib}/wowotek/glHelper.hpp ${lib}/wowotek/type.hpp
	${CC} ${CFLAGS} -c ${lib}/wowotek/glHelper.cpp -o ${odir}/wlib.o

# src/entities/
entity.o: src/entities/entity.hpp src/entities/entity.cpp
	${CC} ${CFLAGS} -c src/entities/entity.cpp -o ${odir}/entity.o

cell.o: src/entities/cell.cpp src/entities/cell.hpp
	${CC} ${CFLAGS} -c src/entities/cell.cpp -o ${odir}/cell.o

entities.o: entity.o cell.o wlib.o
	ld -r ${odir}/entity.o ${odir}/cell.o -o ${odir}/entities.o
	rm ${odir}/entity.o ${odir}/cell.o


# src/game/
control.o: src/game/control.hpp src/game/control.cpp
	${CC} ${CFLAGS} -c src/game/control.cpp -o ${odir}/control.o

render.o: src/game/render.hpp src/game/render.cpp
	${CC} ${CFLAGS} -c src/game/render.cpp -o ${odir}/render.o

game.o: control.o render.o
	ld -r ${odir}/control.o ${odir}/render.o -o ${odir}/game.o
	rm ${odir}/control.o ${odir}/render.o

# src/
main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o ${odir}/main.o

# bin/
evo.o: wlib.o entities.o game.o main.o
	ld -r ${odir}/main.o ${odir}/game.o ${odir}/entities.o ${odir}/wlib.o -o ${odir}/evo.o

Evocellution: evo.o
	${CC} ${CFLAGS} ${odir}/evo.o ${CLINK} -o bin/Evocellution