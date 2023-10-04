#include "tui.hpp"
#include "music_record.hpp"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>

void TUI::clrscr() { system(TUI::_escape_command); }

char TUI::show_menu_prompt() {
  char option = '0';
  while (option < '1' || option > '4') {

    std::cout << TUI_MESSAGES::menu_message << std::endl;
    std::cout << TUI_MESSAGES::menu_prompt << std::flush;
    std::cin >> option;
    clrscr();
  }
  return option;
}

void TUI::first_menu(Repository &repo) {
  MusicRecord *record = new MusicRecord;
  std::cout << TUI_MESSAGES::first_option << std::endl;
  // Ask prompts and then write them down
  std::cout << TUI_MESSAGES::title_prompt << std::flush;
  std::cin >> record->title;

  std::cout << TUI_MESSAGES::artist_prompt << std::flush;
  std::cin >> record->artist;

  std::cout << TUI_MESSAGES::release_year_prompt << std::flush;
  std::cin >> record->year;

  std::cout << TUI_MESSAGES::sold_count_prompt << std::flush;
  std::cin >> record->sold_count;

  std::cout << TUI_MESSAGES::listens_count_prompt << std::flush;
  std::cin >> record->listens_count;

  show_headers();
  std::cout << record->to_string() << std::endl;

  repo.create_record(record);
}

void TUI::show_headers() {
  for (const auto &header : TUI_MESSAGES::table_headers) {
    std::cout << std::left << std::setw(16) << header;
  }
  std::cout << std::endl;
}

void TUI::display_table(std::vector<MusicRecord *> records) {
  std::cout << "Total: " << records.size() << '\n';
  show_headers();
  for (const auto record : records) {
    std::cout << record->to_string() << '\n';
  }
  std::cout << std::flush;
}

void TUI::second_menu(Repository &repo) {
  display_table(repo.get_all_records());
}

void TUI::third_menu(Repository &repo) {
  std::vector<MusicRecord *> matching_records;

  char menu_option = '0';

  while (menu_option < '1' || menu_option > '5') {
    std::cout << TUI_MESSAGES::fourth_option << std::endl;
    std::cout << TUI_MESSAGES::menu_prompt << std::flush;
    std::cin >> menu_option;
    clrscr();
  }
  switch (menu_option) {
  case '1': {
    std::string title_to_search;

    std::cout << "Please, enter the title of track: " << std::flush;
    std::cin >> title_to_search;
    std::cout << "Searching..." << std::endl;

    matching_records = repo.find_by_title(title_to_search);
    break;
  }
  case '2': {
    std::string artist_to_search;

    std::cout << "Please, enter the artist of track: " << std::flush;
    std::cin >> artist_to_search;
    std::cout << "Searching..." << std::endl;

    matching_records = repo.find_by_artist(artist_to_search);
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

    matching_records = repo.find_by_year(year_from, year_to);
    break;
  }
  case '4': {
    int sold_from;
    int sold_to;
    std::cout << "Please, enter the first range of the sold count to search: "
              << std::flush;
    std::cin >> sold_from;
    std::cout << "Please, enter the last range of the sold count to search: "
              << std::flush;
    std::cin >> sold_to;
    std::cout << "Searching..." << std::endl;

    matching_records = repo.find_by_sold_count(sold_from, sold_to);

    break;
  }
  case '5': {
    int listens_from;
    int listens_to;
    std::cout
        << "Please, enter the first range of the listens count to search: "
        << std::flush;
    std::cin >> listens_from;
    std::cout << "Please, enter the last range of the listens count to search: "
              << std::flush;
    std::cin >> listens_to;
    std::cout << "Searching..." << std::endl;

    matching_records = repo.find_by_listens_count(listens_from, listens_to);

    break;
  }
  }
  display_table(matching_records);
}

void TUI::fourth_menu() {
  std::cout << TUI_MESSAGES::exit_message << std::endl;
}

void TUI::show_prompt() {
  char _;
  std::cout << "Write any char to continue.." << std::endl;
  std::cin >> _;
}
