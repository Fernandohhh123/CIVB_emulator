COMPILER = g++
COMPILERFLAGS = -std=c++17 -Wall -Wextra
SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ = $(patsubst %.cpp, obj/%.o, $(notdir $(SRC)))
COMPILERFLAGSDEBUG = -g -std=c++17 -Wall -Wextra -linclude

VPATH = $(sort $(dir $(SRC)))

all: bin/civb

obj/%.o: %.cpp
	mkdir -p obj
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@

bin/civb: $(OBJ)
	mkdir -p bin
	$(COMPILER) $(OBJ) -o bin/civb


.PHONY: clean
clean:
	rm -rf obj bin

.PHONY: debug
debug:
	mkdir -p debug
	mkdir -p obj
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@
	$(COMPILER) $(COMPILERFLAGS) $(OBJ) -o debug/civb_debug
