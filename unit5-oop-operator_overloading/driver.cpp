/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 04/18/2023
 *
 * This program (driver) defines a class called listType that represents a list of integers. The class includes several member functions, which allow for basic operations on the list, such as retrieving the size and maximum size of the list, checking whether the list is empty or full, searching for an element in the list, inserting elements into the list, and removing elements from the list.
 *
 * */
#include "HW9_Darnell.h"

int main() {
  // create a new listType object with a maximum size of 10
  listType myList(10);
  
  // insert some elements into the list
  myList.insert(3);
  myList.insert(7);
  myList.insert(1);
  
  // test the search() function
  int index = myList.search(7);
  if (index == -1) {
    std::cout << "Element not found\n";
  } else {
    std::cout << "Element found at index " << index << "\n";
  }
  
  // test the at() function
  int element = myList.at(1);
  std::cout << "Element at index 1: " << element << "\n";
  
  // insert an element at a specific index
  bool inserted = myList.insert(1, 5);
  if (inserted) {
    std::cout << "Element inserted at index 1\n";
  } else {
    std::cout << "Failed to insert element\n";
  }
  
  // remove an element at a specific index
  bool removed = myList.remove(2);
  if (removed) {
    std::cout << "Element removed from index 2\n";
  } else {
    std::cout << "Failed to remove element\n";
  }
  
  // test the + operator
  listType otherList(5);
  otherList.insert(4);
  otherList.insert(6);
  otherList.insert(2);
  listType combinedList = myList + otherList;
  std::cout << "Combined list: " << combinedList << "\n";
  
  return 0;
}

