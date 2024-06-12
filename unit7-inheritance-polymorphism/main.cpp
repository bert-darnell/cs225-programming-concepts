/* Bert Darnell
 * Kenneth Dewey
 * CS225 HW11
 * 4/30/2023
 *
 * This program is the driver file for a class called arrayListType and two derived classes, unorderedArrayListType and queue. The arrayListType class contains member functions for manipulating an array list, including checking if it is empty or full, getting the size and max size of the list, and performing various insertions, deletions. It also contains virtual functions for performing a search and for inserting, replacing, and removing elements.

The unorderedArrayListType class is a derived class that inherits from arrayListType and provides its own implementation for the virtual functions

The queue class is another derived class that inherits from unorderedArrayListType and provides member functions for performing functions such as enqueue and dequeue. It also overrides the insertion and removal function.

 * */
#include "HW11_Darnell.h"
//--------------
// client code
//--------------


int main()
{
  queue myQueue;

  std::cout << "Is the queue empty? " << std::boolalpha << myQueue.isEmpty() << std::endl;
  std::cout << "The size of the queue is: " << myQueue.size() << std::endl;
  std::cout << "Adding 11, 22, 33, 44, and 55 to the queue" << std::endl;
  myQueue.enque(11);
  myQueue.enque(22);
  myQueue.enque(33);
  myQueue.enque(44);
  myQueue.enque(55);
  std::cout << "Is the queue empty? " << std::boolalpha << myQueue.isEmpty() << std::endl;
  std::cout << "The size of the queue is: " << myQueue.size() << std::endl;
  std::cout << "The front of the queue is: " << myQueue.front() << std::endl;
  std::cout << "The back of the queue is: " << myQueue.back() << std::endl;
  std::cout << "Overloaded output of the queue: " << myQueue << std::endl;
  std::cout << "Dequeuing the front element: " << myQueue.deque() << std::endl;
  std::cout << "The front of the queue is now: " << myQueue.front() << std::endl;
  std::cout << "The size of the queue is now: " << myQueue.size() << std::endl;
  std::cout << "Dequeuing all elements of the queue:" << std::endl;
  while (myQueue.isEmpty() != true) { std::cout << myQueue.deque() << std::endl; }
  std::cout << "Is the queue empty? " << std::boolalpha << myQueue.isEmpty() << std::endl;

  return 0;
} // End main()
