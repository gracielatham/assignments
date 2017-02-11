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
#include<fstream>
#include<math.h>

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
*    none
* @Returns:
*    void
*/
    
    void readFile(){
    }

/**
* @FunctionName: writeFile
* @Description: 
*     writes new data into file
* @Params:
*    none
* @Returns:
*    void
*/
    
    void writeFile(){
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
       
    }
    ~ImagerManip(){
    }
};

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");  
    

  return 0;
    
}
