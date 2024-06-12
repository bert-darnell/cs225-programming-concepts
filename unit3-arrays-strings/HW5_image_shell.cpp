// HW5_image_shell.cpp (shell code. ADD CODE #1 and #2)
// by Bin "Crystal" Peng, CS225
// image processing
// blur an image. print it on screen

#include <iostream>
#include <iomanip> // std::setw()


//----------------------------------------------
// global declarations
//----------------------------------------------

// max dimension of 2D array
const int MAX_ROW = 100;
const int MAX_COL = 100;


//----------------------------------------------
// function declarations
//----------------------------------------------


// blur an image
// Pre: pic filled with height x width numbers
// Post: pic is blurred using a 3 x 3 predefined weight mask

// ADD CODE #1: function declaration

// END ADD CODE #1


// print an image on screen
void printImage(const int pic[][MAX_COL]/*IN*/, int height/*IN*/, int width/*IN*/);
// Pre: pic filled with height x width numbers
// Post: image printed to screen. The height and width are printed first and then the image file data is printed


//----------------------------------------------

int main()
{
  // one image
  int image[MAX_ROW][MAX_COL] = {
    { 10, 100, 10, 100, 10, 100 },
    { 10, 300, 10, 300, 10, 300 },
    { 100, 10, 100, 10, 100, 10 },
    { 300, 10, 300, 10, 300, 10 } };

  int imgHeight = 4; // height of image
  int imgWidth = 6;  // width of image

  // process the image
  blur(image, imgHeight, imgWidth);
  printImage(image, imgHeight, imgWidth);

  return 0;
} // end main


//----------------------------------------------
// Function Implementation
//----------------------------------------------


// blur an image
// Pre: pic filled with height x width numbers
// Post: pic is blurred using a 3 x 3 predefined weight mask

// ADD CODE #2: implementation of function blur

// END ADD CODE #2


// print an image to output stream obj out
void printImage(const int pic[][MAX_COL]/*IN*/, int height/*IN*/, int width/*IN*/)
{
  std::cout << height << ' ' << width << '\n';
  for (int row = 0; row < height; row++)
  {
    for (int col = 0; col < width; col++)
    {
      std::cout << std::setw(4) << pic[row][col];
    }
    std::cout << '\n';
  }

} // end printImage
