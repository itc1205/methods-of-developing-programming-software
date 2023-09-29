#include "music_record.hpp"
#include <iomanip>
#include <iterator>
#include <sstream>
MusicRecord *MusicRecord::from_string(std::string str) {
  // Lets convert our string into the stream
  std::istringstream iss(str);
  // Then lets create our pointer to the struct
  MusicRecord *record = new MusicRecord;
  // Title | artist | year | sold_count | listens_count
  iss >> record->title >> record->artist >> record->year >> record->sold_count >> record->listens_count;
  return record;
}

std::string MusicRecord::to_string() {
  std::stringstream ss;
  // Title | artist | year | sold_count | listens_count
  ss << std::left << std::setw(SIZEOFCHARFIELD) << this->title
     << std::setw(SIZEOFCHARFIELD) << this->artist << std::setw(SIZEOFCHARFIELD)
     << this->year << std::setw(SIZEOFCHARFIELD) << this->sold_count << std::setw(SIZEOFCHARFIELD) << this->listens_count;
  return ss.str();
}
