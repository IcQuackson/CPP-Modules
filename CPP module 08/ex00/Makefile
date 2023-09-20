# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := program

# Source files and object files
CPP_FILES := $(SRC_DIR)/main.cpp
TPP_FILES := $(SRC_DIR)/easyfind.tpp
SRC := $(CPP_FILES) $(TPP_FILES)
OBJ := $(BUILD_DIR)/main.o $(BUILD_DIR)/easyfind.tpp.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/easyfind.tpp.o: $(SRC_DIR)/easyfind.tpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -x c++ -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

rerun: re
	./$(TARGET)

run: all
	./$(TARGET)

gdb: all
	gdb $(TARGET)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY: all clean fclean re rerun test run
