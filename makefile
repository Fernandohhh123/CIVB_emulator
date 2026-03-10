COMPILER = g++
COMPILERFLAGS = -std=c++17 -Wall -Wextra -linclude
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))


all: bin/civb

obj/%.o: src/%.cpp
	mkdir -p obj
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@


bin/civb: $(OBJ)
	mkdir -p bin
	$(COMPILER) $(OBJ) -o bin/civb


.PHONY: clean
clean:
	rm -rf obj bin

