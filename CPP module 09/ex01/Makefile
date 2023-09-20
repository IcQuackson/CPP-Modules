# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := rpn

# Source files and object files
SRC := src/main.cpp src/RPN.cpp
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
ARGS = "8 9 * 9 - 9 - 9 - 4 - 1 +"

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I includes -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

rerun: re run

run: all
	./$(TARGET) $(ARGS)

gdb: all
	gdb --args $(TARGET) $(ARGS)

lldb: all
	lldb $(TARGET) -- $(ARGS)

test: all
	./$(TARGET)
	@echo "\n"
	./$(TARGET) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "\n"
	./$(TARGET) "7 7 * 7 -"
	@echo "\n"
	./$(TARGET) "1 2 * 2 / 2 * 2 4 - +"
	@echo "\n"
	./$(TARGET) "(1 + 1)"
	@echo "\n"
	./$(TARGET) "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 +"
	@echo "\n"
	./$(TARGET) "1 2 3 4 5 6 7 * 3"
	@echo "\n"
	./$(TARGET) "1 2 3 4 5 6 7 * g"

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

.PHONY: all clean fclean re rerun test run