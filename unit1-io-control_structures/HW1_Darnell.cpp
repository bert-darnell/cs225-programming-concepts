/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * Unit 1 - Homework 1
 * 3/18/2023
 *
 *
 * This program takes a "curSalary.txt" file with names, salaries, and percentages, then  calculates the new salary
 * from the the raise percentage, and saves the the formated result to "updatedSalary.txt" 
 *
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
  // Open files
  std::ifstream inFile("curSalary.txt");
  std::ofstream outFile("updatedSalary.txt"); 

  // Checks if file can open or terminates
  if (inFile.fail())
  {
    std::cerr << "can't open input file. Abort.\n";
    return 1;
  }
  if (outFile.fail())
  {
    std::cerr << "can't open output file. Abort.\n";
    return 1;
  }

  // Variables
  std::string firstName;
  std::string lastName;
  double salary;
  double raisePercent;
  int count = 0;

  // Iterates file to variables
  while (inFile >> lastName >> firstName >> salary >> raisePercent)
  {
    count++;
    raisePercent = raisePercent / 100;	// converts percentage
    salary += salary * raisePercent;	// updates salary

    // Saves to file
    outFile << firstName << " " << lastName << " " << std::fixed << std::setprecision(2) << salary << std::endl;
  }
  // Print statement
  std::cout <<  count << " records saved to \"updatedSalary.txt\"" << std::endl;

  // Closes file streams
  inFile.close();
  outFile.close();

  return 0;
}
