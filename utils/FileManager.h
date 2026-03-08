#pragma once
#include <string>
#include <fstream>

class FileManager {
public:
    static void saveReading(const std::string &content, const std::string &filename = "data/history.txt") {
        std::ofstream file(filename, std::ios::app);
        if(file.is_open()) {
            file << content << "\n\n";
            file.close();
        }
    }
};