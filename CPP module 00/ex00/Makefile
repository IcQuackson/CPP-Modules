# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := megaphone

# Source files and object files
SRC := src/megaphone.cpp
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

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

test: all
	./$(TARGET) "shhhhh... I think the students are asleep..."
	./$(TARGET) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(TARGET)

run: all
	./$(TARGET)