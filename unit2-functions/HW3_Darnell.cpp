/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225 Unit2 HW3
 * 03/25/2023
 *
 * This is a C++ program that uses a menu to allow the user to 
 * choose between converting a time from 12-hour to 24-hour format,
 * or vice versa. The program prompts the user for the input time,
 * and then converts it using the appropriate function. Finally,
 * the program displays the converted time.
 *
 * */

#include <iostream>
#include <string>

// Displays menu with options to the user
void display_menu() {
  std::cout << "1. Convert 24-hour notation to 12-hour notation" << std::endl;
  std::cout << "2. Convert 12-hour notation to 24-hour notation" << std::endl;
  std::cout << "0. Quit" << std::endl;
}
// Prompts the user for input (hour, minute, am/pm)
void get_input(int& hour, int& minute, std::string& am_pm, bool ask_am_pm) {
  std::cout << "\nEnter hour: ";
  std::cin >> hour;
  std::cout << "Enter the minute: ";
  std::cin >> minute;
  if (ask_am_pm == false) { // Checks if it 24-hour or 12-hour notation for prompt of AM/PM
    std::cout << "Enter AM or PM: ";
    std::cin >> am_pm;
  }
}
// Converts time from 24-hour notation to 12-hour notation
void convert_to_12_hour(int hour, int minute, std::string am_pm, int& hour_12, std::string& am_pm_12) {
  
  if (hour == 0) { // If 12am sets 12-hour value to 12 and AM
    hour_12 = 12;
    am_pm_12 = "AM";
  } 
  else if (hour == 12) { // If 12pm sets 12-hour to 12 and PM
    hour_12 = 12;
    am_pm_12 = "PM";
  } 
  else if (hour < 12) { // If before 12pm set AM
    hour_12 = hour;
    am_pm_12 = "AM";
  } 
  else { // Sets PM and subtracts 12 from the hour
    hour_12 = hour - 12;
    am_pm_12 = "PM";
  }
}

// Converts time from 12-hour to 24-hour. 
void convert_to_24_hour(int hour_12, int minute, std::string am_pm, int& hour_24) {

  if (hour_12 == 12 && am_pm == "AM") { // If 12am set the 24-hour to 0
    hour_24 = 0;
  } 
  else if (hour_12 == 12 && am_pm == "PM") { // If 12pm set the 24-hour to 12
    hour_24 = 12;
  } 
  else { // Add 12 to the hour if it's PM
    if (am_pm == "PM") {
      hour_24 = hour_12 + 12;
    }
    else { // Uses the same hour for 24-hour time
      hour_24 = hour_12;
    }
  }
}

// Displays the time in 12-hour or 24-hour format
void display_time(int hour, int minute, std::string am_pm = "") {

  std::cout << "\nThe time is: " << hour << ":";

  if (minute < 10) { // Adds a leading 0 if minute is less then 10
    std::cout << "0";
  }
  std::cout << minute << " " << am_pm << "\n" << std::endl;
}


int main() {
  int options, hour, minute, hour_12, hour_24;
  std::string am_pm, am_pm_12;
  do { // Prompts user untill program is exited with "0".
    display_menu();
    std::cout << "Options: ";
    std::cin >> options;
    switch (options) {
      case 1: // 24-hour notation function calls
        get_input(hour, minute, am_pm, true);
        convert_to_12_hour(hour, minute, am_pm, hour_12, am_pm_12);
        display_time(hour_12, minute, am_pm_12);
        break;
      case 2: // 12-hour notation function calls
        get_input(hour_12, minute, am_pm, false);
        convert_to_24_hour(hour_12, minute, am_pm, hour_24);
        display_time(hour_24, minute);
        break;
      case 0: // Exits program.
        std::cout << "\nGoodbye!\n" << std::endl;
        break;
      default:
        std::cout << "\nInvalid option.\n" << std::endl;
        break;
    }
  } while (options != 0); 
  return 0;
}
