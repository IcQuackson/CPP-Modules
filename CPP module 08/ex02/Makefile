# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := program

# Source files and object files
SRC_CPP := $(SRC_DIR)/main.cpp
SRC_TPP := $(SRC_DIR)/MutantStack.tpp
OBJ := $(SRC_CPP:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o) $(SRC_TPP:$(SRC_DIR)/%.tpp=$(BUILD_DIR)/%.tpp.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.tpp.o: $(SRC_DIR)/%.tpp | $(BUILD_DIR)
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
