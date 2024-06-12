/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 4/23/2023
 *
 * This is a C++ program that defines a class called DynListType which is a dynamic list implementation that is able to expand or shrink as needed. The program defines several functions for the DynListType class, including a constructor and a destructor, as well as functions to get the size and maximum size of the list, check if it is empty or full, search for an element, retrieve an element at a given index, insert an element at the end or at a given index, and remove an element at a given index. The program also overloads the << and = operators for printing the list and copying the contents of one list into another.
 *
 * */

#ifndef HW10_DARNELL_H
#define HW10_DARNELL_H

#include <iostream>
#include <cassert>

class DynListType {
public:
  
  // Constructor for the DynListType class that initializes a new object with a specified maximum size.
  DynListType(int maxSize = 5);
  
  // Destructor for the DynListType class that frees the memory allocated to the dataPtr array.
  ~DynListType();
  
  // Returns the number of elements in the DynListType object.
  int getSize() const;
  
  // Returns the maximum number of elements that can be stored in the DynListType object.
  int getMaxSize() const;
  
  // Returns a boolean indicating whether the DynListType object contains any elements
  bool isEmpty() const;
  
  // Returns a boolean indicating whether the DynListType object has reached its maximum capacity.
  bool isFull() const;
  
  // Searches the DynListType object for a specified element and returns the index of its first occurrence. Returns -1 if the element is not found.
  int search(int element) const;
  
  // Returns the value of the element at the specified index in the DynListType object. Throws an out-of-range exception if the index is invalid.
  int at(int index) const;
  
  // Inserts a new element at the end of the DynListType object. Returns a boolean indicating whether the insertion was successful.
  bool insert(int element);
  
  // Inserts a new element at the end of the DynListType object. Returns a boolean indicating whether the insertion was successful.
  bool insert(int index, int element);
  
  // Inserts a new element at the specified index in the DynListType object. Returns a boolean indicating whether the insertion was successful.
  bool remove(int index);
  
  // Removes the element at the specified index from the DynListType object. Returns a boolean indicating whether the removal was successful.
  bool operator==(const DynListType& other) const;
  
  // Overloaded equality operator that compares two DynListType objects and returns a boolean indicating whether they are equal.
  DynListType& operator=(const DynListType& other);
  
  // Copy constructor that initializes a new DynListType object with the same values as another.
  DynListType(const DynListType& other);

  //Overloaded output stream operator that outputs the contents of a DynListType object to an output stream.
  friend std::ostream& operator<<(std::ostream& os, const DynListType& list);

private:
  int* dataPtr;   // A pointer to the array of elements stored in the DynListType object.
  int size;   // The number of elements currently stored in the DynListType object.
  int maxSize;    // The maximum number of elements that can be stored in the DynListType object.
  
  // Doubles the size of the current DynListType object. Copies the current elements to a new array of size maxSize * 2 and deletes the old array. The size and dataPtr members of the object are updated to the new size and location of the array.
  void doubleSize();

};
#endif //HW10_DARNELL_H
