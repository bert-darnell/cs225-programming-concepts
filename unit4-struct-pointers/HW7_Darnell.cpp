/* Bert Darnell
 * Kenneth Dewey
 * CS225 - HW7
 * 4/8/2023
 *
 * *This is a C++ program that performs digit-by-digit addition of two positive integers entered by the user. It uses dynamic arrays to store the input integers and their sum, so the maxsize of an integer doesn't matter.
 * */

#include <iostream>
#include <cstring>


// This function prompts the user to enter a positive integer, converts the string to an integer array, and returns a pointer to the array.
// Pre: Takes a reference to an integer variable (numOfDigits).
// Post: Returns a pointer to an integer array containing, and sets numOfDigits to the length of the interger entered by the user.

int* readNum(int& numOfDigits/*OUT*/)
{
  std::string numString;
  std::cout << "Enter a positive integer: ";
  std::cin >> numString;

  numOfDigits = numString.length();
  int* numArr = new int[numOfDigits];
  for (int i = 0; i < numOfDigits; i++) {
    numArr[i] = numString[i] - '0';
  }
  return numArr;
}

// This function calculates the sum of the two input arrays by performing digit-by-digit addition, and returns the sum as an array. It also removes any leading zeros from the sum array.
// Pre: Takes two integer arrays (pNum1, pNum2) and their lengths (numOfDigits1, numOfDigits2) as well as a reference to an integer variable (numOfDigitsResult).
// Post: Returns a pointer to an integer array containing the sum of the two input arrays, and sets numOfDigitsResult to the number of digits in the sum.

int* sumNum(const int * pNum1/*IN*/, int numOfDigits1/*IN*/,
            const int * pNum2/*IN*/, int numOfDigits2/*IN*/,
            int& numOfDigitsResult/*OUT*/)
{
  // determine the length of the result array
  numOfDigitsResult = std::max(numOfDigits1, numOfDigits2) + 1; // +1 for possible carry
  int* result = new int[numOfDigitsResult];

  // perform addition digit by digit, right to left
  int carry = 0;
  for (int i = 0; i < numOfDigitsResult; i++) {
    int sum = carry;
    if (i < numOfDigits1) {
      sum += pNum1[numOfDigits1 - 1 - i];
    }
    if (i < numOfDigits2) {
      sum += pNum2[numOfDigits2 - 1 - i];
    }
    carry = sum / 10;
    result[numOfDigitsResult - 1 - i] = sum % 10;
  }

  // remove leading zeros from the result array
  while (numOfDigitsResult > 1 && result[0] == 0) {
    numOfDigitsResult--;
    for (int i = 0; i < numOfDigitsResult; i++) {
      result[i] = result[i + 1];
    }
  }

  return result;
}

// Prints each digit in the input array to the console.
// Pre: Takes a pointer to an integer array (pNum) and its length (numOfDigits) as a paramter.
// Post: Prints the digits in the integer array to the console.

void print(const int* pNum/*IN*/, int numOfDigits/*IN*/)
{
  for (int i = 0; i < numOfDigits; i++) {
    std::cout << pNum[i];
  }
  std::cout << std::endl;
}

// Reads in two positive integers using the readNum function, calculates their sum using the sumNum function, and prints the result using the print function. It then deletes the dynamic arrays used.
int main()
{
  int numOfDigits1, numOfDigits2, numOfDigitsResult;
  int* pNum1 = readNum(numOfDigits1);
  int* pNum2 = readNum(numOfDigits2);
  int* pSum = sumNum(pNum1, numOfDigits1, pNum2, numOfDigits2, numOfDigitsResult);
  print(pSum, numOfDigitsResult);
  delete[] pNum1;
  delete[] pNum2;
  delete[] pSum;

  return 0;
}

