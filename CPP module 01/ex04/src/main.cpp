#include <iostream>
#include <fstream>

void replace(char *file_name, std::string targetString, std::string replacementString) {

    if (targetString.empty() && replacementString.empty()) {
        return;
    }
    std::ifstream inFile(file_name);
    if (!inFile) {
        std::cout << "File: " << file_name << " does not exist!" << std::endl;
        return;
    }
    std::string content;
    char ch;
    while (inFile.get(ch)) {
        content += ch;
        // Checks if the current content string has the targetString at the end
        if (content.size() >= targetString.size() &&
            content.substr(content.size() - targetString.size()) == targetString) {
            // Removes target string from the end of the string and adds the replacement string
            content = content.substr(0, content.size() - targetString.size()) + replacementString;
        }
    }
    inFile.close();

    // Write new content in same file
    std::ofstream outFile(file_name);
    if (!outFile) {
        std::cout << "Error opening file: " << file_name << std::endl;
        return;
    }
    outFile << content;
    outFile.close();
}

int main(int argc, char **argv) {

    if (argc != 4) {
        return 0;
    }
    replace(argv[1], argv[2], argv[3]);
}
