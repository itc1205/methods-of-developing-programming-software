#pragma once
#include "database.hpp"
#include "music_record.hpp"
#include <vector>

// Class for abstracting working with MusicRecords
// Behaviour: The class will automatically manage all the memory for storing
// MusicRecords When repository goes out of scope, all MusicRecords will be
// pointing to the freed memory!!!
class Repository {
public:
  // Can return nullptr if wont find any
  std::vector<MusicRecord *> find_by_title(std::string title);
  // Can return nullptr if wont find any
  std::vector<MusicRecord *> find_by_artist(std::string artist);
  // Can return nullptr if wont find any
  std::vector<MusicRecord *> find_by_year(int begin_year, int end_year);
  // Can return nullptr if wont find any
  std::vector<MusicRecord *> find_by_sold_count(int begin_listens, int end_listens);

  // Can return nullptr if wont find any
  MusicRecord *find_by_record_index(int index);

  // Returns pointer to the vec of pointers
  std::vector<MusicRecord *> get_all_records();

  // Will take ownership of pointer
  void create_record(MusicRecord *record);
  Repository(std::string filename);
  ~Repository();

private:
  // Vector for storing pointers to the structs (to not overhelm our stack)
  std::vector<MusicRecord *> records;
  Database db;
  // Method for synchronizing database and file
  void syncrhonize();
};