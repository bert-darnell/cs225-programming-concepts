/* Bert Darnell
 * Kenneth Dewey
 * CS225 HW11
 * 4/30/2023
 *
 * This program is the implementation file for a class called arrayListType and two derived classes, unorderedArrayListType and queue. The arrayListType class contains member functions for manipulating an array list, including checking if it is empty or full, getting the size and max size of the list, and performing various insertions, deletions. It also contains virtual functions for performing a search and for inserting, replacing, and removing elements.

The unorderedArrayListType class is a derived class that inherits from arrayListType and provides its own implementation for the virtual functions

The queue class is another derived class that inherits from unorderedArrayListType and provides member functions for performing functions such as enqueue and dequeue. It also overrides the insertion and removal function.

 * */

#include "HW11_Darnell.h"
//---------------------
// Implementation
//---------------------

bool arrayListType::isEmpty() const
{
  return (length == 0);
} //end isEmpty

bool arrayListType::isFull() const
{
  return (length == maxSize);
} //end isFull

int arrayListType::listSize() const
{
  return length;
} //end listSize

int arrayListType::maxListSize() const
{
  return maxSize;
} //end maxListSize

bool arrayListType::isItemAtEqual(int location, int item)  const
{
  if (location < 0 || location >= length)
  {
    std::cout << "The location of the item to be removed "
      << "is out of range.\n";

    return false;
  }
  else
    return (list[location] == item);
} //end isItemAtEqual

void arrayListType::removeAt(int location)
{
  if (location < 0 || location >= length)
    std::cout << "The location of the item to be removed "
    << "is out of range.\n";
  else
  {
    for (int i = location; i < length - 1; i++)
      list[i] = list[i + 1];

    length--;
  }
} //end removeAt

void arrayListType::retrieveAt(int location, int& retItem) const
{
  if (location < 0 || location >= length)
    std::cout << "The location of the item to be retrieved is "
    << "out of range\n";
  else
    retItem = list[location];
} //end retrieveAt

void arrayListType::clearList()
{
  length = 0;
} //end clearList

arrayListType::arrayListType(int size)
{
  if (size <= 0)
  {
    std::cout << "The array size must be positive. Creating "
      << "an array of the size 100.\n";

    maxSize = 100;
  }
  else
    maxSize = size;

  length = 0;

  list = new int[maxSize];
  //std::cout << "constructor of alt: " << this << "\n"; // testing
} //end constructor

arrayListType::~arrayListType()
{
  delete[] list;
  //std::cout << "destructor of alt: " << this << "\n"; // testing
} //end destructor

arrayListType::arrayListType(const arrayListType& otherList)
{
  maxSize = otherList.maxSize;
  length = otherList.length;

  list = new int[maxSize];  //create the array

  for (int j = 0; j < length; j++)  //copy otherList
    list[j] = otherList.list[j];

  //std::cout << "copy constructor of alt: " << this << "\n"; // testing
}//end copy constructor

//--------------------
// non-member, friend
//--------------------
std::ostream& operator<<(std::ostream& out, const arrayListType& obj)
{
  for (int i = 0; i < obj.length; i++)
    out << obj.list[i] << " ";
  return out;
} //end operator<<

//---------------------
//---------------------

void unorderedArrayListType::insertAt(int location,
  int insertItem)
{
  if (location < 0 || location >= maxSize)
    std::cout << "The position of the item to be inserted "
    << "is out of range.\n";
  else if (length >= maxSize)  //list is full
    std::cout << "Cannot insert in a full list\n";
  else
  {
    for (int i = length; i > location; i--)
      list[i] = list[i - 1];  //move the elements down

    list[location] = insertItem; //insert the item at
    //the specified position

    length++; //increment the length
  }
} //end insertAt

void unorderedArrayListType::insertEnd(int insertItem)
{
  if (length >= maxSize)  //the list is full
    std::cout << "Cannot insert in a full list.\n";
  else
  {
    list[length] = insertItem; //insert the item at the end
    length++; //increment the length
  }
} //end insertEnd

int unorderedArrayListType::seqSearch(int searchItem) const
{
  for (int loc = 0; loc < length; loc++)
    if (list[loc] == searchItem)
      return loc;

  return -1; // not found
} //end seqSearch

void unorderedArrayListType::remove(int removeItem)
{
  if (length == 0)
    std::cout << "Cannot delete from an empty list.\n";
  else
  {
    int loc = seqSearch(removeItem);

    if (loc != -1)
      removeAt(loc);
    else
      std::cout << "The item to be deleted is not in the list\n.";
  }
} //end remove

void unorderedArrayListType::replaceAt(int location, int repItem)
{
  if (location < 0 || location >= length)
    std::cout << "The location of the item to be "
    << "replaced is out of range.\n";
  else
    list[location] = repItem;
} //end replaceAt

unorderedArrayListType::unorderedArrayListType(int size)
: arrayListType(size)
{
  //std::cout << "constructor of unorderedalt: " << this << "\n"; // testing
}  //end constructor

//---------------------
//---------------------

// Pre: None
// Post: Returns true if the queue is empty, false otherwise.
  bool queue::isEmpty() const {
  return arrayListType::isEmpty(); // calls base class function 
}
// Pre: None
// Post-condition: Returns the number of elements in the list
int queue::size() const {
  return arrayListType::listSize(); // calls base class function 
}

// Pre: The queue is not empty.
// Post: The value of the first element in the queue is returned.
int queue::front() const {
  return list[0];
}

// Pre: The queue is not empty.
// Post: The value of the last element in the queue is returned.
int queue::back() const {
  return list[length - 1]; 
}

// Pre: The queue is not full.
// Post: The item is added to the back of the queue.
void queue::enque(int newItem) {
  insertEnd(newItem); // adds the new item to the end of the list
}

// Pre: The queue is not empty.
// Post: The front element of the queue is removed and returned.
int queue::deque() {
  int item = list[0]; // sets 'item' to the front element 
  removeAt(0); // removes the front element from the list
  return item;
}

// output operator overload for queue class
std::ostream& operator<<(std::ostream& os, const queue& q)
{
  // iterate over queue elements and print them out
  for (int i = 0; i < q.listSize(); i++) {
    int item;
    q.retrieveAt(i, item);
    os << item;
    if (i < q.listSize()) {
      os << " ";
    }
  }
  return os;
}
