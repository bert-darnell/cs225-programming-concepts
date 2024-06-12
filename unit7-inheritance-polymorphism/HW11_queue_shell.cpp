// HW11_queue_shell.cpp (shell)
// CS225
// By Bin "Crystal" Peng
//
// ch12 inheritance, virtual
//
// HW11. Build a queue class via inheritance
// queue inherits unorderedArrayListType (ch12. p881)
// unorderedArrayListType inherits arrayListType (ch12. p874)

#include <iostream>

//--------------
// arrayListType (super)
//--------------
class arrayListType
{
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
  int *list;    //array to hold the list elements
  int length;   //length of the list
  int maxSize;  //the maximum size of the list
};

//--------------
// unorderedArrayListType (sub)
//--------------

class unorderedArrayListType : public arrayListType
{
public:
  void insertAt(int location, int insertItem);
  void insertEnd(int insertItem);
  void replaceAt(int location, int repItem);
  int seqSearch(int searchItem) const;
  void remove(int removeItem);

  unorderedArrayListType(int size = 100); //Constructor
};

//--------------
// queue (grand-sub)
//--------------
class queue : private unorderedArrayListType
{
public:
  bool isEmpty() const; // test whether queue is empty
  // Post: returns true if queue is empty, otherwise returns false

  int size() const; // return size
  // Post: returns the number of elements in the queue

  int front() const; // returns the element at the front of the queue. This should be the "oldest" element, the same element that will be removed if deque() is called next
  // Pre: the queue is not empty
  // Post: returns the element at the front of the queue

  int back() const; // returns the element at the back of the queue. This should be the "youngest" element, the same element that was added into the queue most recently using enque()
  // Pre: the queue is not empty
  // Post: returns the element at the back of the queue

  void enque(int newItem); // insert one element at the back of the queue, after its current last element (the "youngest" element before this enque)
  // Post: newItem added at the end of the queue, after the current last element

  int deque(); // remove one element from the front of the queue. The "oldest" element should be removed
  // Pre: the queue is not empty
  // Post: the item at the front of the queue is removed from the queue and returned

  queue(int size = 100);
  // Post: queue initialized with capacity being size param and contains 0 elements.
  //       if no size is specified, 100 is used for the capacity
};



//--------------
// client code
//--------------


int main()
{
  unorderedArrayListType intList(25);

  for (int i = 0; i < 8; i++)
    intList.insertEnd(i * 10 + 5);
  std::cout << "intList: " << intList << std::endl;

  //Create temp and initialize it using intList
  unorderedArrayListType temp(intList);
  std::cout << "temp: " << temp << std::endl;

  //Replace the first element of temp.
  temp.replaceAt(0, -75);
  std::cout << "temp first element replaced: " << temp << std::endl;

  std::cout << "intList: " << intList << std::endl;

  return 0;
} // end main

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


