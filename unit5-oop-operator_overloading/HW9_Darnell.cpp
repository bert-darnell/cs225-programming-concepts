/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 04/18/2023
 *
 * This program (implementation) defines a class called listType that represents a list of integers. The class includes several member functions, which allow for basic operations on the list, such as retrieving the size and maximum size of the list, checking whether the list is empty or full, searching for an element in the list, inserting elements into the list, removing elements from the list, and overloads oporators.
 *
 * */
#include "HW9_Darnell.h"

// Constructor: sets the maximum size of the list based on the value passed as an argument, or sets it to a default value (5) if no argument is given.
listType::listType(int max) {
  if (max <= 0) {
    maxSize = 5;
  } else if (max > MAX) {
    maxSize = MAX;
  } else {
    maxSize = max;
  }
  size = 0;
}

int listType::getSize() const {
  return size;
}

int listType::getMaxSize() const {
  return maxSize;
}

bool listType::isEmpty() const {
  return size == 0;
}

bool listType::isFull() const {
  return size == maxSize;
}

// Pre: listType object has been initialized and has a size value, dataArr has been initialized with integers
// Post: will return the index of the first occurrence of element if found, otherwise return -1
int listType::search(int element) const {
  for (int i = 0; i < size; i++) {
    if (dataArr[i] == element) {
      return i;
    }
  }
  return -1;
}

// Pre: listType object has been initialized and has a size value, dataArr has been initialized with integers
// Post: return the element at the given index if the index is within range, assert will fail if index is out of range
int listType::at(int index) const {
  assert(index >= 0 && index < size);
  return dataArr[index];
}

// Pre: listType object has been initialized and has a size and maxSize value, dataArr has been initialized with integers
// Post: will insert an element at the end of the listType object and return true, return false if the listType object is full
bool listType::insert(int element) {
  if (isFull()) {
    return false;
  }
  dataArr[size] = element;
  size++;
  return true;
}

// Pre: listType object has been initialized and has a size and maxSize value, dataArr has been initialized with integers
// Post: will insert an element at the end of the listType object and return true, return false if the listType object is full
bool listType::insert(int index, int element) {
  if (isFull() || index < 0 || index > size) {
    return false;
  }
  for (int i = size; i > index; i--) {
    dataArr[i] = dataArr[i - 1];
  }
  dataArr[index] = element;
  size++;
  return true;
}

// Pre: listType object has been initialized and has a size and maxSize value, dataArr has been initialized with integers
// Post: will remove the element at the given index if the index is within range and return true, return false otherwise
bool listType::remove(int index) {
  if (isEmpty() || index < 0 || index >= size) {
    return false;
  }
  for (int i = index; i < size - 1; i++) {
    dataArr[i] = dataArr[i + 1];
  }
  size--;
  return true;
}

// Pre: listType object has been initialized and has a size and maxSize value, dataArr has been initialized with integers
// Post: outputs a formatted string representation of the listType object to the given output stream and returns the output stream
std::ostream& operator<<(std::ostream& os, const listType& lt) {
  os << "[";
  for (int i = 0; i < lt.size; i++) {
    os << lt.dataArr[i];
    if (i != lt.size - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

// Pre: listType objects to be added have been initialized with their respective size and maxSize values, and dataArr has been initialized with integers
// Post: returns a new listType object containing the elements of both listType objects, with the size equal to the sum of their sizes and the maxSize equal to the sum of their maxSize values. If either listType object is full, then only the elements that fit in the resulting listType object will be added.
listType listType::operator+(const listType& other) const {
  listType result(this->maxSize + other.maxSize);
  for (int i = 0; i < this->size; i++) {
    result.insert(this->dataArr[i]);
  }
  for (int i = 0; i < other.size; i++) {
    result.insert(other.dataArr[i]);
  }
  return result;
}

