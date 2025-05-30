#include <ReadFile.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

std::string readFile(const char* filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filepath << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
