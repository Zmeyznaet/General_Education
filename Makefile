TARGET := develop
CXX := clang
CXX_FLAGS := -Wall -Wextra -pedantic -Werror -lstdc++ -std=c++17 -ggdb

BIN := bin
SRC := src
INCLUDE := include
LIB := lib

all: $(BIN)/$(TARGET)

clean: $(BIN)/$(TARGET)
	rm -rf $(BIN)/$(TARGET)

$(BIN)/$(TARGET): $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) -o $(BIN)/$(TARGET) $(SRC)/main.cpp