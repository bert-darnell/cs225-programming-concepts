/* Bert Darnell
 * Kenneth Dewey
 * CS225 HW11
 * 4/30/2023
 *
 * This program is the header file for a class called arrayListType and two derived classes, unorderedArrayListType and queue. The arrayListType class contains member functions for manipulating an array list, including checking if it is empty or full, getting the size and max size of the list, and performing various insertions, deletions. It also contains virtual functions for performing a search and for inserting, replacing, and removing elements.

The unorderedArrayListType class is a derived class that inherits from arrayListType and provides its own implementation for the virtual functions

The queue class is another derived class that inherits from unorderedArrayListType and provides member functions for performing functions such as enqueue and dequeue. It also overrides the insertion and removal function.

 * */

#ifndef HEADER_FILE_NAME_H
#define HEADER_FILE_NAME_H

#include <iostream>

class arrayListType {
  friend std::ostream& operator<<(std::ostream&, const arrayListType&);

public:
  bool isEmpty() const;
  bool isFull() const;
  int listSize() const;
  int maxListSize() const;

  bool isItemAtEqual(int location, int item) const;
  void removeAt(int location);
  void retrieveAt(int location, int& retItem) const;
  void clearList();

  virtual int seqSearch(int searchItem) const = 0;
  virtual void insertAt(int location, int insertItem) = 0;
  virtual void insertEnd(int insertItem) = 0;
  virtual void replaceAt(int location, int repItem) = 0;
  virtual void remove(int removeItem) = 0;

  arrayListType(int size = 100);
  arrayListType(const arrayListType& otherList);
  virtual ~arrayListType();

protected:
  int* list;    //array to hold the list elements
  int length;   //length of the list
  int maxSize;  //the maximum size of the list
};

class unorderedArrayListType : public arrayListType {
public:
  void insertAt(int location, int insertItem);
  void insertEnd(int insertItem);
  void replaceAt(int location, int repItem);
  int seqSearch(int searchItem) const;
  void remove(int removeItem);

  unorderedArrayListType(int size = 100);  //Constructor
};

class queue : private unorderedArrayListType {
public:
  friend std::ostream& operator<<(std::ostream& os, const queue& q);

  bool isEmpty() const;  // test whether queue is empty
  // Post: returns true if queue is empty, otherwise returns false

  int size() const;  // return size
  // Post: returns the number of elements in the queue

  int front() const;  // returns the element at the front of the queue. This should be the "oldest" element, the same element that will be removed if deque() is called next
  // Pre: the queue is not empty
  // Post: returns the element at the front of the queue

  int back() const;  // returns the element at the back of the queue. This should be the "youngest" element, the same element that was added into the queue most recently using enque()
  // Pre: the queue is not empty
  // Post: returns the element at the back of the queue

  void enque(int newItem);  // insert one element at the back of the queue, after its current last element (the "youngest" element before this enque)
  // Post: newItem added at the end of the queue, after the current last element

  int deque();  // remove one element from the front of the queue. The "oldest" element should be removed
  // Pre: the queue is not empty
  // Post: the item at the front of the queue is removed from the queue and returned

  queue(int size = 100) : unorderedArrayListType(size) {}  // constructor
  // Post: queue initialized with capacity being size param and contains 0 elements.
  //       if no size is specified, 100 is used for the capacity
};

#endif // HEADER_FILE_NAME_H

