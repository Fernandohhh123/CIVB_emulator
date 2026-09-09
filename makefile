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

# ------------------------------------------------------------------------

CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra 
COMPILERFLAGSDEBUG ?= -g -std=c++17 -Wall -Wextra -Include
LDFLAGS ?=

CXXFLAGS += $(RPM_OPT_FLAGS)

SRCS := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ := $(patsubst %.cpp, obj/%.o, $(notdir $(SRCS)))

INSTALLPATH ?= /usr/bin/civb
TARGET := civb

PREFIX ?= /usr/local
BINDIR := $(PREFIX)/bin

VPATH = $(sort $(dir $(SRCS)))

all: $(TARGET)

obj/%.o: %.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) 

.PHONY: clean
clean:
	rm -rf obj $(TARGET)

.PHONY: debug
debug:
	mkdir -p debug
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@
	$(CXX) $(CXXFLAGS) $(OBJ) -o debug/civb_debug

.PHONY: install
install: $(TARGET)
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)

.PHONY: uninstall
uninstall:
	rm -rf $(DESTDIR)$(BINDIR)/$(TARGET)
