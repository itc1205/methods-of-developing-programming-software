#pragma once
#include <string>

#define SIZEOFCHARFIELD 16

class MusicRecord {
public:
  // Will format MusicRecord from string
  static MusicRecord *from_string(std::string str);
  // Will format string from MusicRecord
  std::string to_string();

  char title[SIZEOFCHARFIELD];
  char artist[SIZEOFCHARFIELD];
  int year;
  int sold_count;
  int listens_count;
};
