/**
* Homework 3 - Fix Print Function
* Gracie Latham
* Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date: 01 03 2017
*/

/**
* FunctionName: Print
* Description: 
*     Insert an if statement to look for when the queue is full 
* Params:
*    NONE
* Returns:
*    NONE
*/
  void Print(){

    int Index = Front;
    if(Full()){
  
    while(Index != Rear){
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
    }
    cout<<endl;
  }
 }
