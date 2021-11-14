.PHONY:= all clean

TARGET := develop
CXX := clang++
CXX_FLAGS := -Wall -Wextra -pedantic -Werror -std=c++17 -ggdb

BIN := bin
SRC := src
INCLUDE := include
OBJ := obj

all: $(BIN)/$(TARGET)

clean:
	rm -rf $(BIN)/$(TARGET) $(OBJ)/*

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -c -I $(INCLUDE) -o $@ $<

$(BIN)/$(TARGET): $(OBJ)/main.o
	$(CXX) $(CXX_FLAGS) -o $@ $<