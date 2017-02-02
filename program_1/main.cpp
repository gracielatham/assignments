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
* @Returns:
*    void
*/

void grayScale(rgb** image,int width,int height){
 
}

/**
* @FunctionName: changeColor
* @Description: 
*     Loops through a 2D array and assigns newColor to each location of array
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    rgb newColor - assigns new colors for array
* @Returns:
*    void
*/

void changeColor(rgb** image,int width, int height, rgb newColor){
   // loop through image
   // assign newColor to each location in array
  
}

/**
* @FunctionName: readImage
* @Description: 
*     Loops through a 2D array and reads the values of the array
* @Params:
*    rgb** image - 2D array holding rgb values
*    int &width - width of image
*    int &height - height of image
*    ofstream &ofile - opens and uses output file 
* @Returns:
*    void
*/

void readImage(rgb** image,int &width,int &height,ofstream &ofile){
    
}

/**
* @FunctionName: saveImage 
* @Description: 
*     Loops through a 2D array and saves the new image
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    ofstream &ofile - opens and uses output file 
* @Returns:
*    void
*/

void saveImage(rgb** image,int width,int height,ofstream &ofile){
    
}

int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   
    
    int width;               //width of image
    int height;              //height of image
    
    rgb **imgArray;         //Pointer var for our 2D array          
    
    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size.
    
    imgArray = new rgb*[height];    //This array points to every row
    
    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    
     //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    
    //We could make any changes we want to the color image here
     
    
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
