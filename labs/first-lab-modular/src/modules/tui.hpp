#pragma once
#include "music_record.hpp"
#include "repository.hpp"
#include <vector>

namespace TUI {

#ifdef __linux__
const auto _escape_command = "clear";
#else
const auto _escape_command = "clr";
#endif

void clrscr();

// Will return choice char
char show_menu_prompt();

void show_headers();
void first_menu(Repository &repo);
void second_menu(Repository &repo);
void third_menu(Repository &repo);
void fourth_menu();

void display_table(std::vector<MusicRecord*> records);

void show_prompt();
} // namespace TUI

namespace TUI_MESSAGES {

const auto menu_message = "Welcome to the Music catalogue!\n\n"
                          "Choose what you want to do:\n\n"
                          "1.INSERT - Insert new record\n\n"
                          "2.LIST - List all records\n\n"
                          "3.LOOKUP - Lookup for record by their attribute\n\n"
                          "4.Exit - Gracefully close program";

const auto menu_prompt = "Choose your option~: ";

// Table headers (tabbed out)
const auto table_headers = {"Title", "Artist", "Release year", "Sold count", "Listens count"};
// First option message
const auto first_option = "You choosed inserting new record\n\n"
                          "To continue you must answer all prompts";

const auto title_prompt = "Set the title name: ";
const auto artist_prompt = "Set the artist name: ";
const auto release_year_prompt = "Set the release year: ";
const auto sold_count_prompt = "Set the sold count: ";
const auto listens_count_prompt = "Set the listens count: ";

// Third option message
const auto fourth_option =
    "Search prompt!\n\n"
    "Choose what attribute by you want to perform search:\n\n"
    "1.Title - Look for the title\n\n"
    "2.Artist - Look for artist\n\n"
    "3.Year - Look for year\n\n"
    "4.Sold count - Look for sold count\n\n"
    "5.Listens - Look for listens";

// Fourth option message
const auto exit_message = "Closing the program!";

} // namespace TUI_MESSAGES