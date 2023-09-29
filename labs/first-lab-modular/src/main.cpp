#include <iostream>

#include "constants.hpp"
#include "modules/database.hpp"
#include "modules/music_record.hpp"
#include "modules/repository.hpp"
#include "modules/tui.hpp"

int main() {
  auto repo = Repository(constants::database_uri);

  bool is_running = true;
  while (is_running) {
    TUI::clrscr();
    auto choice = TUI::show_menu_prompt();
    switch (choice) {
    case '1': {
      TUI::first_menu(repo);
      break;
    }
    case '2': {
      TUI::second_menu(repo);
      break;
    }
    case '3': {
      TUI::third_menu(repo);
      break;
    }
    case '4': {
      TUI::fourth_menu();
      is_running = false;
      break;
    }
    }
    TUI::show_prompt();
  }
}
