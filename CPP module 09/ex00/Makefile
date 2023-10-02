# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := btc

# Source files and object files
SRC := src/main.cpp src/BitcoinExchange.cpp
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
ARGS = inputs/good.csv

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
	gdb $(TARGET) --eval-command="run $(ARGS)"

lldb: all
	lldb $(TARGET) -- $(ARGS)

test: all
	./$(TARGET)
	@echo "\n"
	./$(TARGET) inputs/good.csv
	@echo "\n"
	./$(TARGET) inputs/bad.csv
	@echo "\n"
	./$(TARGET) inputs/does_not_exist.csv
	@echo "\n"
	./$(TARGET) inputs/bad_header.csv
	@echo "\n"
	./$(TARGET) inputs/no_records.csv
	@echo "\n"
	./$(TARGET) inputs/empty_line.csv
	@echo "\n"
	./$(TARGET) inputs/empty.csv

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) $(ARGS)

.PHONY: all clean fclean re rerun test run