# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

# Directories and file names
SRC_DIR := src
BUILD_DIR := build
TARGET := program

# Source files and object files
SRC := src/main.cpp\
	   src/Bureaucrat.cpp\
	   src/AForm.cpp\
	   src/ShrubberyCreationForm.cpp\
	   src/RobotomyRequestForm.cpp\
	   src/PresidentialPardonForm.cpp\
	   src/Intern.cpp

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
	rm *_shrubbery

fclean: clean
	rm -f $(TARGET)

re: fclean all

rerun: re
	./$(TARGET)

test: all
	./$(TARGET)

run: all
	./$(TARGET)

gdb: all
	gdb $(TARGET)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

.PHONY: all clean fclean re rerun test run