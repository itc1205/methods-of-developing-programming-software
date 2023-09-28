#include <cstdint>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#ifdef __linux__
const auto _escape_command = "clear";
#else
const auto _escape_command = "clr";
#endif
// !WARNING Redefined function for cross-compiling
void clrscr() { system(_escape_command); }

const auto filename = "music_database.dat";

//// Messages part
// Message to show in menu
const auto menu_message = "Welcome to the Music catalogue!\n\n"
                          "Choose what you want to do:\n\n"
                          "1.INSERT - Insert new record\n\n"
                          "2.LIST - List all records\n\n"
                          "3.LOOKUP - Lookup for record by their attribute\n\n"
                          "4.Exit - Gracefully close program";

const auto menu_prompt = "Choose your option~: ";

// Table headers (tabbed out)
const auto table_headers = {"Title", "Artist", "Release year", "Sold count"};
// First option message
const auto first_option = "You choosed inserting new record\n\n"
                          "To continue you must answer all prompts";

const auto title_prompt = "Set the title name: ";
const auto artist_prompt = "Set the artist name: ";
const auto release_year_prompt = "Set the release year: ";
const auto sold_count_prompt = "Set the sold count: ";

// Fourth option message
const auto exit_message = "Closing the program!";

//// Struct part
struct Track {
  char title[16];
  char artist_name[16];
  unsigned int release_year;
  unsigned int sold_count;
};

//// Program part
int main() {
  // Initialize variables
  bool is_running = true;
  char option = '0';
  // Initialize connection to the file

  while (is_running) {
    // Show our message and prompt
    // Read input from user, until we got the right one
    while (option < '1' || option > '4') {
      std::cout << menu_message << std::endl;
      std::cout << menu_prompt << std::flush;
      std::cin >> option;
      clrscr();
    }
    switch (option) {
    case '1': {
      clrscr();
      Track new_track;
      std::cout << first_option << std::endl;
      // Fill in all fields of the struct
      std::cout << title_prompt << std::endl;
      std::cin >> new_track.title;

      std::cout << artist_prompt << std::endl;
      std::cin >> new_track.artist_name;

      std::cout << release_year_prompt << std::endl;
      std::cin >> new_track.release_year;

      std::cout << sold_count_prompt << std::endl;
      std::cin >> new_track.sold_count;
      // Show the struct

      for (const auto &header : table_headers) {
        std::cout << std::left << std::setw(16) << header;
      }
      std::cout << std::endl;
      std::cout << std::left << std::setw(16) << new_track.title
                << std::setw(16) << new_track.artist_name << std::setw(16)
                << new_track.release_year << std::setw(16)
                << new_track.sold_count << std::endl;

      std::cout << "Performing write operation..." << std::endl;

      std::ofstream fout(filename, std::ios_base::app);

      fout << std::left << std::setw(16) << new_track.title << std::setw(16)
           << new_track.artist_name << std::setw(16) << new_track.release_year
           << std::setw(16) << new_track.sold_count << std::endl;
      std::cout << "Done!" << std::endl;
      fout.close();
      char _;
      std::cout << "Write any char to continue.." << std::endl;
      std::cin >> _;

      break;
    }
    case '2': {
      clrscr();
      std::ifstream fin(filename);
      std::vector<Track> tracks;
      std::cout << "Performing read operation..." << std::endl;
      while (true) {
        Track new_track;
        fin >> new_track.title >> new_track.artist_name >>
            new_track.release_year >> new_track.sold_count;
        if (fin.eof())
          break;
        tracks.push_back(new_track);
      }
      std::cout << "Done reading: " << tracks.size() << " tracks" << std::endl;

      for (const auto &header : table_headers) {
        std::cout << std::left << std::setw(16) << header;
      }
      std::cout << std::endl;

      for (auto &track : tracks) {
        std::cout << std::left << std::setw(16) << track.title << std::setw(16)
                  << track.artist_name << std::setw(16) << track.release_year
                  << std::setw(16) << track.sold_count << '\n';
      }
      std::cout << std::endl;

      char _;
      std::cout << "Write any char to continue.." << std::endl;
      std::cin >> _;

      break;
    }
    case '3': {
      std::ifstream fin(filename);
      std::vector<Track> tracks;
      std::cout << "Performing read operation..." << std::endl;
      while (true) {
        Track new_track;
        fin >> new_track.title >> new_track.artist_name >>
            new_track.release_year >> new_track.sold_count;
        if (fin.eof())
          break;
        tracks.push_back(new_track);
      }
      std::cout << "Done reading: " << tracks.size() << " tracks" << std::endl;

      char menu_option;
      std::cout << "" << std::endl;

      break;
    }
    case '4': {
      is_running = false;
      break;
    }
    }
    option = '0';
  }
}
