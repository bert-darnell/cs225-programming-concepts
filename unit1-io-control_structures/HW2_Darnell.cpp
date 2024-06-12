/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225 Unit2 HW1
 * 03/19/2023
 *
 * This program prompts the user to enter a telephone number expressed in letters
 * or digits and outputs the corresponding telephone number in digits. If the user
 * enters more than seven characters, only the first seven valid digits are
 * processed. A hyphen is also output after the third digit. The user is allowed to
 * use digits, both uppercase and lowercase letters, and spaces between words. If a
 * number contains invalid letters, such as a number with special characters, the
 * program reports the error and terminates processing of that phone number. However,
 * the program does not terminate entirely and instead prompts the user to enter
 * another number.
 *
 * */


#include <iostream>
#include <cctype>

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter telephone number in letters or digits: ";

    std::cin >> std::ws;  // discard any leading white space
    std::getline(std::cin, input);  // read the input as a whole line
    //    std::cin >> input;

    // Initialize variables.
    std::string output = "";
    char c;
    int count = 0; 

    // Loops through user input.
    for (char c : input){

      if (c != ' '){  // Required even with std::ws, if white space was the first thing user typed, it took on second character.

        // Keeps the phone number to the initial 7 digits.
        if (count == 7){ break;}

        // Checks if input is a digit and adds the it to output
        if ( isdigit(c)){
          output += c;
          count++;
        } else {

          // Changes alpha characters to uppercase then adds the corresponding digit to output.
          switch (toupper(c)) {
            case 'A': case 'B': case 'C': output += "2"; count++; break;
            case 'D': case 'E': case 'F': output += "3"; count++; break;
            case 'G': case 'H': case 'I': output += "4"; count++; break;
            case 'J': case 'K': case 'L': output += "5"; count++; break;
            case 'M': case 'N': case 'O': output += "6"; count++; break;
            case 'P': case 'Q': case 'R': case 'S': output += "7"; count++; break;
            case 'T': case 'U': case 'V': output += "8"; count++; break;
            case 'W': case 'X': case 'Y': case 'Z': output += "9"; count++; break;
            default: break;
          }
        }
      }
    }

    // Format and outputs phone number, else it checks for invlid input length.
    if (count == 7){
      output.insert(3, "-");
      std::cout << output << std::endl;
    } else {
      std::cout << "Invalid phone number" << std::endl;
    }

    // Prompt to quit.
    std::cout << "Enter another phone number? (y/n): ";
    char answer;
    std::cin >> answer;
    if (answer == 'N' || answer == 'n') { break; }
  }
  return 0;
}

