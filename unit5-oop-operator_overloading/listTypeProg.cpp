// listTypeProg.cpp (HW9 shell code)
// CS225
// HW9. a statically allocated array based list type class with overloaded operators


const int MAX = 100; // max capacity for all listType objects

class listType
{
public:
  listType(int max = 5); // constructor
  // Post: maxSize <-- max. if max is not specified or <=0, default value 5 will be used. if max > MAX, MAX will be used
  //       size <-- 0.

  int getSize() const { return size; }            // return # of elements actually stored
  int getMaxSize() const { return maxSize; }      // return capacity
  bool isEmpty() const { return size == 0; }
  bool isFull() const { return size == maxSize; }

  int search(int element) const;  // look for an item. return index of first occurrence
  int at(int index) const;        // return element at a specific location
  void print() const;             // print content of list on screen in format of [a, b, c]

  bool insert(int element);             // append/insert an element at the end
  bool insert(int index, int element);
    // insert an element into location index
    // Shifts the element currently at that index (if any) and any subsequent elements to the right

  bool remove(int index);         // remove element at the specified location

private:
  int dataArr[MAX]; // static array storing data items
  int size;         // actual # of elements stored. size <= maxSize
  int maxSize;      // The capacity of this listType obj. 0 <= maxSize <= MAX.
};


