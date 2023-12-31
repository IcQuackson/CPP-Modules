# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := program

# Source files and object files
SRC := src/main.cpp
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

INFILE = in.txt
TARGET_STR = aa
REPLACEMENT_STR = bb
ARGS = in.txt aa bb

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

rerun: re
	./$(TARGET)

test: all
	./$(TARGET)

run: all
	./$(TARGET) $(ARGS)

gdb: all
	gdb $(TARGET) $(ARGS)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

.PHONY: all clean fclean re rerun test run