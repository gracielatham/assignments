

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb{
    int r;
    int g;
    int b;
};

void flipVert(rgb** image,int width,int height){
    // your code
}

void flipHorz(rgb** image,int width,int height){
    // your code
}

void grayScale(rgb** image,int width,int height){
    // your code
}

void readImage(rgb** image,int &width,int &height,ofstream &ofile){
    // Hmmm, what's up with the width and height references
}
void saveImage(rgb** image,int width,int height,ofstream &ofile){
    // your code
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
