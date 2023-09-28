#include <iostream>

#include "constants.hpp"
#include "modules/database.hpp"
#include "modules/music_record.hpp"
#include "modules/repository.hpp"
#include "modules/tui.hpp"

int main() {
  Repository repo = Repository(constants::database_uri);
  MusicRecord *record = MusicRecord::from_string("AwA Hewwo 2003 1205");
  repo.create_record(record);
  for (auto &record : repo.get_all_records()) {
    std::cout << record->to_string() << '\n';
  }
  std::cout << std::endl;
}