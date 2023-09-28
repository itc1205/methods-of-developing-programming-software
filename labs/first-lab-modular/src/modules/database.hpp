#pragma once
#include <fstream>
#include <string>
#include <vector>

// Database class will be used for manipulations with file
class Database {
private:
  std::string filename;

public:
  std::vector<std::string> read();
  void write(std::string string_to_write);
  Database(std::string filename);
};