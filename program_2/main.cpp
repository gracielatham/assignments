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
    ifstream infile;
    ofstream ofile;
    string ifile_name;
    string ofile_name;

    void readFile(){
    }

    void writeFile(){
    }

public:
    ImageManip(){
    }

    void flipVert(string ifile_name,string ofile_name){

    }

    void flipHorz(string ifile_name,string ofile_name){
       
    }

    void grayScale(string ifile_name,string ofile_name){
       
    }
    ~ImagerManip(){
    }
}

int main() {
    ifile.open("bot.txt");
    ofile.open("bot2.txt");  
    

  return 0;
    
