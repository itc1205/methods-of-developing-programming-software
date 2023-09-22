#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
//// Messages part
// Message to show in menu
const auto menu_message = "Welcome to the Music catalogue!\n\n"
                          "Choose what you want to do:\n\n"
                          "1.INSERT - Insert new record\n\n"
                          "2.LIST - List all records\n\n"
                          "3.LOOKUP - Lookup for record by their attribute\n\n"
                          "4.Exit - Gracefully close program";

const auto menu_prompt = "Choose your option~: ";

// First option message
const auto first_option = "You choosed inserting new record\n\n"
                          "To continue you must answer all prompts\n\n";

const auto title_prompt = "Set the title name: ";
const auto artist_prompt = "Set the artist name: ";
const auto release_year_prompt = "Set the release year: ";
const auto sold_count_prompt = "Set the sold count: ";

//// Struct part
// Track struct is 128 bytes long, and should be easly enough cachable
struct Track {
  char32_t title;
  char32_t artist_name;
  uint32_t release_year;
  uint32_t sold_count;
};

//// Program part
int main() {
  // Initialize variables
  bool is_running = true;
  int option = 0;
  std::vector<Track> tracks;
  while (is_running) {
    // Show our message and prompt
    std::cout << menu_message << std::endl;
    std::cout << menu_prompt;
    // Read input from user, untill we got the right one
    while (option < 1 && option > 4) {
      std::cin >> option;
    }

    switch (option) {
    case 1: {
      Track new_track;
    }
    case 2: {
    }
    case 3: {
    }
    case 4: {
    }
    }
  }
}
