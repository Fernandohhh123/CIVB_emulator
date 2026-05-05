COMPILER = gcc
COMPILERFLAGS = -std=c++17 -Wall -Wextra
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, ../../obj%.o, $(SRC))

all: $(OBJ)

../../obj%.o: %.cpp
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@
