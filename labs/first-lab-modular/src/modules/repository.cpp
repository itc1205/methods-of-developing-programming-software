#include "repository.hpp"
#include "database.hpp"
#include "music_record.hpp"
#include <vector>

Repository::Repository(std::string filename) : db(filename) {
    // Syncrhonize our vector with database
    syncrhonize();
}

void Repository::create_record(MusicRecord *record) {
  db.write(record->to_string());
  records.push_back(record);
}

void Repository::syncrhonize() {
  // Clean up all records
  for (auto &record : records) {
    delete record;
  }
  records.clear();
  // Reload them from database
  for (auto &line : db.read()) {
    records.push_back(MusicRecord::from_string(line));
  }
}

Repository::~Repository() {
  // Free all memory from records
  for (auto &record : records) {
    delete record;
  }
  records.clear();
}

std::vector<MusicRecord *> Repository::find_by_title(std::string title) {
  std::vector<MusicRecord *> result;
  for (auto &record : records) {
    if (record->title == title) {
      result.push_back(record);
    }
  }
  return result;
}

std::vector<MusicRecord *> Repository::find_by_artist(std::string artist) {
  std::vector<MusicRecord *> result;
  for (auto &record : records) {
    if (record->artist == artist) {
      result.push_back(record);
    }
  }
  return result;
}
std::vector<MusicRecord *> Repository::find_by_year(int begin_year,
                                                    int end_year) {
  std::vector<MusicRecord *> result;
  for (auto &record : records) {
    if (record->year >= begin_year && record->year <= end_year) {
      result.push_back(record);
    }
  }
  return result;
}

std::vector<MusicRecord *> Repository::get_all_records() {
    return records;
}

std::vector<MusicRecord *> Repository::find_by_sold_count(int begin_count,
                                                          int end_count) {
  std::vector<MusicRecord *> result;
  for (auto &record : records) {
    if (record->sold_count >= begin_count && record->sold_count <= end_count) {
      result.push_back(record);
    }
  }
  return result;
}