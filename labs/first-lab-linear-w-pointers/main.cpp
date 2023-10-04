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
const auto _escape_command = "cls";
#endif
// !WARNING Redefined console-clear function for cross-compiling
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
const auto listen_count_prompt = "Set the listen count: ";
// Third option message
const auto fourth_option =
    "Search prompt!\n\n"
    "Choose what attribute by you want to perform search:\n\n"
    "1.Title - Look for the title\n\n"
    "2.Artist - Look for artist\n\n"
    "3.Year - Look for year\n\n"
    "4.Listens - Look for listens";

// Fourth option message
const auto exit_message = "Closing the program!";

//// Struct part
struct Track {
  char title[16];
  char artist_name[16];
  unsigned int release_year;
  unsigned int sold_count;
  unsigned int listen_count;
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
      Track* new_track = new Track;
      std::cout << first_option << std::endl;
      // Fill in all fields of the struct
      std::cout << title_prompt << std::endl;
      std::cin >> new_track->title;

      std::cout << artist_prompt << std::endl;
      std::cin >> new_track->artist_name;

      std::cout << release_year_prompt << std::endl;
      std::cin >> new_track->release_year;

      std::cout << sold_count_prompt << std::endl;
      std::cin >> new_track->sold_count;
      // Show the struct

      std::cout << listen_count_prompt << std::endl;
      std::cin >> new_track->listen_count;

      for (const auto &header : table_headers) {
        std::cout << std::left << std::setw(16) << header;
      }
      std::cout << std::endl;
      std::cout << std::left << std::setw(16) << new_track->title
                << std::setw(16) << new_track->artist_name << std::setw(16)
                << new_track->release_year << std::setw(16)
                << new_track->listen_count << std::setw(16)
                << new_track->sold_count << std::endl;

      std::cout << "Performing write operation..." << std::endl;

      std::ofstream fout(filename, std::ios_base::app);

      fout << std::left << std::setw(16) << new_track->title << std::setw(16)
           << new_track->artist_name << std::setw(16) << new_track->release_year
           << std::setw(16) << new_track->sold_count << std::setw(16)
           << new_track->listen_count << std::endl;

      std::cout << "Done!" << std::endl;
      delete new_track;
      fout.close();
      break;
    }
    case '2': {
      std::ifstream fin(filename);
      std::vector<Track*> tracks;
      std::cout << "Performing read operation..." << std::endl;
      while (true) {
        Track* new_track = new Track;
        fin >> new_track->title >> new_track->artist_name >>
            new_track->release_year >> new_track->sold_count >> new_track->listen_count;
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
        std::cout << std::left << std::setw(16) << track->title << std::setw(16)
                  << track->artist_name << std::setw(16) << track->release_year
                  << std::setw(16) << track->sold_count << '\n';
      }
      std::cout << std::endl;

      // Cleanup memory
      for (auto &track : tracks) {
        delete track;
      }
      tracks.clear();
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
      std::cout << "Done reading: " << tracks.size() << " tracks total"
                << std::endl;

      char menu_option = '0';

      while (menu_option < '1' || menu_option > '5') {
        std::cout << fourth_option << std::endl;
        std::cout << menu_prompt << std::flush;
        std::cin >> menu_option;
        clrscr();
      }

      // Pre-reserve vector of tracks
      std::vector<Track> matching_tracks;
      matching_tracks.reserve(tracks.size());

      switch (menu_option) {
      case '1': {
        std::string title_to_search;

        std::cout << "Please, enter the title of track: " << std::flush;
        std::cin >> title_to_search;
        std::cout << "Searching..." << std::endl;

        for (auto &track : tracks) {
          if (track.title == title_to_search) {
            matching_tracks.push_back(track);
          }
        }
        break;
      }
      case '2': {
        std::string artist_to_search;

        std::cout << "Please, enter the artist of track: " << std::flush;
        std::cin >> artist_to_search;
        std::cout << "Searching..." << std::endl;

        for (auto &track : tracks) {
          if (track.title == artist_to_search) {
            matching_tracks.push_back(track);
          }
        }
        break;
      }
      case '3': {
        int year_from;
        int year_to;
        std::cout << "Please, enter the first range of the year to search: "
                  << std::flush;
        std::cin >> year_from;
        std::cout << "Please, enter the last range of the year to search: "
                  << std::flush;
        std::cin >> year_to;
        std::cout << "Searching..." << std::endl;

        for (auto &track : tracks) {
          if (track.release_year >= year_from &&
              track.release_year <= year_to) {
            matching_tracks.push_back(track);
          }
        }

        break;
      }
      case '4': {
        int sold_from;
        int sold_to;
        std::cout
            << "Please, enter the first range of the sold count to search: "
            << std::flush;
        std::cin >> sold_from;
        std::cout
            << "Please, enter the last range of the sold count to search: "
            << std::flush;
        std::cin >> sold_to;
        std::cout << "Searching..." << std::endl;

        for (auto &track : tracks) {
          if (track.sold_count >= sold_from && track.sold_count <= sold_to) {
            matching_tracks.push_back(track);
          }
        }

        break;
      }
      case '5': {
        int listens_from;
        int listens_to;
        std::cout
            << "Please, enter the first range of the listens count to search: "
            << std::flush;
        std::cin >> listens_from;
        std::cout
            << "Please, enter the last range of the listens count to search: "
            << std::flush;
        std::cin >> listens_to;
        std::cout << "Searching..." << std::endl;

        for (auto &track : tracks) {
          if (track.listen_count >= listens_from &&
              track.listen_count <= listens_to) {
            matching_tracks.push_back(track);
          }
        }
        break;
      }
      }

      // Output everything that we have found

      std::cout << "Found tracks: " << matching_tracks.size() << std::endl;

      for (const auto &header : table_headers) {
        std::cout << std::left << std::setw(16) << header;
      }
      std::cout << std::endl;

      for (auto &track : matching_tracks) {
        std::cout << std::left << std::setw(16) << track.title << std::setw(16)
                  << track.artist_name << std::setw(16) << track.release_year
                  << std::setw(16) << track.sold_count << '\n';
      }
      char _;
      std::cout << "Write any char to continue.." << std::endl;
      std::cin >> _;
      break;
    }
    case '4': {
      // Show message and gracefully shut down the program
      std::cout << fourth_option << std::endl;
      is_running = false;
      break;
    }
    }
    char _;
    std::cout << "Write any char to continue.." << std::endl;
    std::cin >> _;

    // Reset the option
    option = '0';
    clrscr();
  }
}
