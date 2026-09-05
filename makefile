# civb - TUI based 4 bit cpu emulator

#    Copyright (C) 2026 Fernando Hernández Valverde

#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

# This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#  You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
#    contact: fernandohdzvalverde@gmail.com


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
