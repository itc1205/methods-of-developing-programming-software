#include "database.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

Database::Database(std::string filename_to_open) {
  filename = filename_to_open;
}

std::vector<std::string> Database::read() {
  std::fstream fileStream(filename);

  std::vector<std::string> lines;
  while (true) {
    std::string line;
    std::getline(fileStream, line);
    if (line.empty()) {
      break;
    }
    lines.push_back(line);
  }
  // Clearing filestream from failbits and rewinding it
  fileStream.clear();
  fileStream.seekg(0);
  return lines;
}

// Appends database
void Database::write(std::string line) {
  std::fstream fileStream(filename, std::ios_base::app);
  fileStream << line << std::endl;
}