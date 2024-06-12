/*
 * Bert Darnell
 * Kenneth Dewey
 * CS225
 * 04/18/2023
 *
 * This program (interface) defines a class called listType that represents a list of integers. The class includes several member functions, which allow for basic operations on the list, such as retrieving the size and maximum size of the list, checking whether the list is empty or full, searching for an element in the list, inserting elements into the list, removing elements from the list, and overloading oporators.
 *
 * */
#ifndef LISTTYPE_H
#define LISTTYPE_H
#include <cassert>
#include <iostream>
#include <fstream>

const int MAX = 100; // Maximum size of the listType object's data array

class listType {
public:
    // Constructor with default value for max
    listType(int max = 5);

    // Function to return the current size of the listType object
    int getSize() const;

    // Function to return the maximum size of the listType object
    int getMaxSize() const;

    // Function to check if the listType object is empty
    bool isEmpty() const;

    // Function to check if the listType object is full
    bool isFull() const;

    // Function to search for an element in the listType object
    int search(int element) const;

    // Function to return the element at a given index in the listType object
    int at(int index) const;

    // Function to insert an element at the end of the listType object
    bool insert(int element);

    // Function to insert an element at a given index in the listType object
    bool insert(int index, int element);

    // Function to remove an element at a given index in the listType object
    bool remove(int index);

    // Overloaded stream insertion operator to print the listType object
    friend std::ostream& operator<<(std::ostream& os, const listType& lt);

    // Overloaded addition operator to concatenate two listType objects
    listType operator+(const listType& other) const;

private:
    int dataArr[MAX]; // Data array to store integers in the listType object
    int size; // Current size of the listType object
    int maxSize; // Maximum size of the listType object
};

#endif // LISTTYPE_H

