/**
* Program-2: Image Manipilation 2
* Gracie Latham
* Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date: 15 02 2017
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct rgb{
    int r;
    int g;
    int b;
};

class ImageManip{
private:
    rgb** image;
    int width;
    int height;
    ifstream ifile;
    ofstream ofile;
    string ifile_name;
    string ofile_name;

/**
* @FunctionName: readFile
* @Description: 
*     Reads in the input file
* @Params:
*    rgb **imgArray - pointer for image rgb
* @Returns:
*    void
*/
    
   void readFile(rgb **imgArray){
      for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
  }

/**
* @FunctionName: writeFile
* @Description: 
*     writes new data into file
* @Params:
*    rgb **imgArray - pointer for image rgb
* @Returns:
*    void
*/
    
     void writeFile(rgb **imgArray){
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
  }

public:
    ImageManip(){
    }

/**
* @FunctionName: flipVert
* @Description: 
*     Flips the image vertically
* @Params:
*   string ifile_name - takes data from infile
*   string ofile_name - prints data to outfile
* @Returns:
*    void
*/
    
    void flipVert(string ifile_name,string ofile_name){
      int Row[256]; 
      for (int i = 0; 0 <= i <= height/2; i++){
      Row[i] = height - 1 - i; 
    }
  }

/**
* @FunctionName: flipHorz
* @Description: 
*    Flips the image horizontally 
* @Params:
*  string ifile_name - takes data from infile
*  string ofile_name - prints data to outfile
* @Returns:
*    void
*/
    
  void flipHorz(string ifile_name,string ofile_name){
      int Col[256];
      for (int i = 0; 0 <= i <= width/2; i++){
        Col[i] = width - 1 - i; 
    }
  }

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*  string ifile_name - takes data from infile
*  string ofile_name - prints data to outfile
* @Returns:
*    void
*/
    
     void grayScale(string ifile_name,string ofile_name){
      int gray;
      for(int i = 0; i <= 255; i++){
        gray = (image[i]->r + image[i]->g + image[i]->b) / 3;
        image[i]->r = gray;
        image[i]->g = gray;
        image[i]->b = gray;
    }   
  }
    ~ImagerManip(){
    }
};

int main() {
    ifstream ifile;
    ofstream ofile;
   
    string ifile_open("bot.txt");
    string ofile_open("bot2.txt");
 
    ImageManip image; 
    
    image.flipVert(ifile_open, ofile_open); 
    
    image.flipHorz(ifile_open, ofile_open);
    
    image.grayScale(ifile_open, ofile_open); 

    return 0;
 }
