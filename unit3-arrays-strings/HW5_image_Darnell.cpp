// HW5_image_shell.cpp (completed code with ADD #1 and ADD #2)
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

// blur weight mask
const int weightMask[3][3] = {  
  {1, 2, 1},
  {2, 2, 2},
  {1, 2, 1} };

// sum of the weight mask. NOTE: could make function to calculate
const int koef = 14;

//----------------------------------------------
// function declarations
//----------------------------------------------

// blur an image
// Pre: pic filled with height x width numbers
// Post: pic is blurred using a 3 x 3 predefined weight mask
void blur(int pic[][MAX_COL]/*INOUT*/, int height/*IN*/, int width/*IN*/);

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
void blur(int pic[][MAX_COL]/*INOUT*/, int height/*IN*/, int width/*IN*/)
{

  // Temporary array to store old values of pic
  int tempPic[MAX_ROW][MAX_COL];
  for (int row = 0; row < height; row++)
  {
    for (int col = 0; col < width; col++)
    {
      tempPic[row][col] = pic[row][col];
    }
  }

  // Iterates through 2d-array.
  for (int row = 1; row < height-1; row++)
  {
    for (int col = 1; col < width-1; col++)
    {
      // Check if pixel has 8 neighbors.
      int neighborCount = 0;
      for (int i = -1; i <= 1; i++)
      {
        for (int j = -1; j <= 1; j++)
        {
          // If pixel is not 0 it's the center of mask and not a counted as a neighbor.    
          if (i != 0 || j != 0)     
          { 
            // If the pixel has negative value it's an invalid neighbor.
            if (pic[row+i][col+j] >= 0) 
            {
              neighborCount++;
            }
          }
        }
      }

      if (neighborCount == 8)
      {
        // Apply the weight mask.
        int sum = 0;
        for (int i = -1; i <= 1; i++)
        {
          for (int j = -1; j <= 1; j++)
          {
            // Summation of the weight * old value.
            sum += weightMask[i+1][j+1] * tempPic[row+i][col+j];
          }
        }
        // Summation divided by koef 
        pic[row][col] = sum / koef;
      }
    }
  }
} // end blur



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
