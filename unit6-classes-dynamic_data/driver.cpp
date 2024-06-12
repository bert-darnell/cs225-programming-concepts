/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 4/23/2023
 *
 * This is a C++ program that defines a class called DynListType which is a dynamic list implementation that is able to expand or shrink as needed. The program defines several functions for the DynListType class, including a constructor and a destructor, as well as functions to get the size and maximum size of the list, check if it is empty or full, search for an element, retrieve an element at a given index, insert an element at the end or at a given index, and remove an element at a given index. The program also overloads the << and = operators for printing the list and copying the contents of one list into another.
 *
 *  Driver function that demonstrates the use of the DynListType class by creating several lists and performing various operations on them.
 *
 * */

#include "HW10_Darnell.h"

int main() {
  // create a DynListType object with maxSize 3
  DynListType list1(3);

  // insert elements into the list
  list1.insert(1);
  list1.insert(2);
  list1.insert(3);

  // test the overloaded assignment operator
  DynListType list2 = list1;
  std::cout << "List1 == List2: " << std::boolalpha << (list1 == list2) << std::endl;

  // remove an element from the list
  list1.remove(1);

  // test the overloaded comparison operator
  std::cout << "List1 == List2: " << std::boolalpha << (list1 == list2) << std::endl;

  // test the copy constructor
  DynListType list3(list1);
  std::cout << "List1 == List3: " << std::boolalpha << (list1 == list3) << std::endl;

  // insert an element into the list at index 1
  list1.insert(1, 9);

  // test the output stream operator
  std::cout << "List1: " << list1 << std::endl;

  return 0;
}

