/* 
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 4/23/2023
 *
 * This is a C++ program that defines a class called DynListType which is a dynamic list implementation that is able to expand or shrink as needed. The program defines several functions for the DynListType class, including a constructor and a destructor, as well as functions to get the size and maximum size of the list, check if it is empty or full, search for an element, retrieve an element at a given index, insert an element at the end or at a given index, and remove an element at a given index. The program also overloads the << and = operators for printing the list and copying the contents of one list into another.
 *
 * */

#include "HW10_Darnell.h"

// Post-condition: Initializes a DynListType object with the given maxSize value. If maxSize is less than or equal to 0, the maxSize value is set to 5. The size of the dataPtr array is set to 0.
DynListType::DynListType(int maxSize) {
  if (maxSize <= 0) // invalid value
    this->maxSize = 5;
  else
    this->maxSize = maxSize;

  dataPtr = new int[this->maxSize];
  size = 0;
}

// Post-condition: Deallocates memory allocated for the dataPtr array.
DynListType::~DynListType() {
  delete[] dataPtr;
}

// Post-condition: Returns the size of the DynListType object.
int DynListType::getSize() const {
  return size;
}

// Post-condition: Returns the maximum size of the DynListType object.
int DynListType::getMaxSize() const {
  return maxSize;
}

// Post-condition: Returns true if the DynListType object is empty, false otherwise.
bool DynListType::isEmpty() const {
  return size == 0;
}

// Post-condition: Returns true if the DynListType object is full, false otherwise.
bool DynListType::isFull() const {
  return size == maxSize;
}

// Post-condition: Returns the index of the first occurrence of the element in the DynListType object, or -1 if the element is not found.
int DynListType::search(int element) const {
  for (int i = 0; i < size; i++) {
    if (dataPtr[i] == element) {
      return i;
    }
  }
  return -1;
}

// Pre-condition: Assumes that the index is a valid index within the DynListType object.
// Post-condition: Returns the element at the given index of the DynListType object.
int DynListType::at(int index) const {
  assert(index >= 0 && index < size);
  return dataPtr[index];
}

// Post-condition: Inserts the given element at the end of the DynListType object. If the DynListType object is full, the size of the object is doubled by calling the private helper function doubleSize(). Returns true upon insertion.
bool DynListType::insert(int element) {
  if (isFull()) {
    doubleSize(); // call private helper function to double the size
  }
  dataPtr[size] = element;
  size++;
  return true;
}

// Pre-condition: Assumes that index is a valid index within the DynListType object.
// Post-condition: Inserts the given element at the end of the DynListType object. If the DynListType object is full, the size of the object is doubled by calling the private helper function doubleSize(). Returns true upon insertion.
bool DynListType::insert(int index, int element) {
  if (isFull() || index < 0 || index > size) {
    return false;
  }
  if (isFull()) {
    doubleSize(); // call private helper function to double the size
  }
  for (int i = size; i > index; i--) {
    dataPtr[i] = dataPtr[i - 1];
  }
  dataPtr[index] = element;
  size++;
  return true;
}

//Pre-condition: Assumes that index is a valid index within the DynListType object.
//Post-condition: Removes the element at the given index of the DynListType object. Returns true upon removal.
bool DynListType::remove(int index) {
  if (isEmpty() || index < 0 || index >= size) {
    return false;
  }
  for (int i = index; i < size - 1; i++) {
    dataPtr[i] = dataPtr[i + 1];
  }
  size--;
  return true;
}

// Post-condition: Overloads the << operator to print the DynListType object.
std::ostream& operator<<(std::ostream& os, const DynListType& list) {
  os << "Size: " << list.getSize() << ", Max Size: " << list.getMaxSize() << ", Elements: ";
  for (int i = 0; i < list.size; i++) {
    os << list.dataPtr[i] << " ";
  }
  return os;
}

// Post-condition: Overloads the = operator to copy the contents of the given DynListType object (other) into the current object. If the object is the same as the current object, no copying is done. The memory previously allocated for the dataPtr array is deallocated and a new array is allocated with the same size as the given object's dataPtr array. Returns a reference to the current object.
DynListType& DynListType::operator=(const DynListType& other) {
  if (this != &other) {
    this->maxSize = other.maxSize;
    this->size = other.size;
    delete[] this->dataPtr;
    this->dataPtr = new int[this->maxSize];
    for (int i = 0; i < this->size; i++) {
      this->dataPtr[i] = other.dataPtr[i];
    }
  }
  return *this;
}

// Pre-conditions: other must be a valid DynListType object.
// Post-conditions: Creates a new DynListType object that is a copy of the other object
DynListType::DynListType(const DynListType& other) {
  this->maxSize = other.maxSize;
  this->size = other.size;
  this->dataPtr = new int[this->maxSize];
  for (int i = 0; i < this->size; i++) {
    this->dataPtr[i] = other.dataPtr[i];
  }
}

//Pre-conditions: other must be a valid DynListType object.
//Post-conditions: Returns true if the current DynListType object is equal to other object. Returns false otherwise.
 bool DynListType::operator==(const DynListType& other) const {
  if (size != other.size) {
    return false;
  }
  for (int i = 0; i < size; i++) {
    if (dataPtr[i] != other.dataPtr[i]) {
      return false;
    }
  }
  return true;
}

// Post-conditions: Doubles the size of the current DynListType object. Copies the current elements to a new array of size maxSize * 2 and deletes the old array. The size and dataPtr members of the object are updated to the new size and location of the array.
void DynListType::doubleSize() {
  int* newDataPtr = new int[maxSize * 2];
  for (int i = 0; i < size; i++) {
    newDataPtr[i] = dataPtr[i];
  }
  delete[] dataPtr;
  dataPtr = newDataPtr;
  maxSize *= 2;
}

