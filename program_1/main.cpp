/**
*Program-1: Image Manipulation
*Gracie Latham 
* Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date:06 02 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb{
    int r;
    int g;
    int b;
};

/**
* FunctionName: flipVert
* Description: 
*     Loops through a 2D array and flips the image Vertically
* Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    int Row[] - Array for rows of image
* Returns:
*    void
*/

void flipVert(rgb** image,int width,int height,int Row[]){
    for (int i = 0; 0 <= i <= height/2; i++){
      Row[i] = height - 1 - i; 
    }
}

/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and flips the image Horizontally
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    int Col[] - Array for columns of image
* @Returns:
*    void
*/

void flipHorz(rgb** image,int width,int height,int Col[]){
    for (int i = 0; 0 <= i <= width/2; i++){
      Col[i] = width - 1 - i; 
    }
 }

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    int gray - the new color that each of the rgb values change to
* @Returns:
*    void
*/

void grayScale(rgb** image, int width, int height, int gray){
    for(int i = 0; i <= 255; i++){
      gray = (image[i]->r + image[i]->g + image[i]->b) / 3;
      image[i]->r = gray;
      image[i]->g = gray;
      image[i]->b = gray;
  } 

/**
* @FunctionName: changeColor
* @Description: 
*     Loops through a 2D array and turns every RGB value into the new color.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    rgb newColor - a struct holding the new color for the image.
* @Returns:
*    void
*/

void changeColor(rgb** image, int width, int height, rgb** newColor){
   // loop through image
   // assign newColor to each location in array
    for(int i = 0; i <= 255; i++){
      newColor[i]->r = 94;
      newColor[i]->g = 137;
      newColor[i]->b = 255;
  }
}

int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   
    
    int width;               //width of image
    int height;              //height of image
    int Row;                 //row of image
    int Col;                 //column of image
    
    rgb **imgArray;         //Pointer var for our 2D array          
    
    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size.
    
    
    imgArray = new rgb*[height];      // This array points to every row
    
    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; // Allocate each row of rgb's
    }
    
    image.flipVert(255, 255, Row);    // Function for flipping Vertically
    
    imgArray = new rgb*[width];       // This array points to every column
    
    for(int i=0;i<width;i++){
      imgArray[i] = new rgb[height];  // Allocate each column of rgb's
    }
    
    image.flipHorz(255, 255, Col);    // Function for flipping Horizontally
    
     //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    
    //We could make any changes we want to the color image here
     image.grayScale(255, 255);       // GrayScaling the image
     
     image.newColor(255, 255);        // Changing values of rgb in the image
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
    
    
  return 0;
}  
