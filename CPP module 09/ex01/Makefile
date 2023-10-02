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
ARGS = "*"

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
	@echo "\033[93mEmpty Input\033[0m"
	./$(TARGET)
	@echo "\n"
	@echo "\033[93minput bigger than 9\033[0m"
	./$(TARGET) "1 2 10"
	@echo "\n"
	@echo "\033[93mDivision by zero\033[0m"
	./$(TARGET) "1 0 /"
	@echo "\n"
	@echo "\033[93mNegative number\033[0m"
	./$(TARGET) "1 -1 +"
	@echo "\n"
	@echo  "\033[93mComplex Arithmetic\033[0m"
	./$(TARGET) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "\n"
	@echo  "\033[93mSingle operator\033[0m"
	./$(TARGET) "*"
	@echo "\n"
	@echo  "\033[93mSimple Arithmetic\033[0m"
	./$(TARGET) "7 7 * 7 -"
	@echo "\n"
	@echo  "\033[93mMixed Operations\033[0m"
	./$(TARGET) "1 2 * 2 / 2 * 2 4 - +"
	@echo "\n"
	@echo  "\033[93mParentheses\033[0m"
	./$(TARGET) "(1 + 1)"
	@echo "\n"
	@echo  "\033[93mSum with too many operands\033[0m"
	./$(TARGET) "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 +"
	@echo "\n"
	@echo  "\033[93mMultiplication with Many Operands\033[0m"
	./$(TARGET) "1 2 3 4 5 6 7 * 3"
	@echo "\n"
	@echo  "\033[93mInvalid Input\033[0m"
	./$(TARGET) "1 2 3 4 5 6 7 * g"
	@echo "\n"
	@echo  "\033[93mArithmetic with Whitespace\033[0m"
	./$(TARGET) "        8 9    *      9 - 9      - 9 - 4 - 1        +     "
	@echo "\n"
	@echo  "\033[93mCharacter-Only Input\033[0m"
	./$(TARGET) "s s  s s s s s"
	@echo "\n"
	@echo  "\033[93mNo Operator\033[0m"
	./$(TARGET) "1 2 3 4 5 6"
	@echo "\n"

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

.PHONY: all clean fclean re rerun test run