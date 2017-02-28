/**
* Homework: Homework-3
* Author: Gracie Latham
* Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date: 01 03 2017
*/

/**
* @FunctionName: Print
* @Description: 
*     You describe your fix here
* @Params:
*    NONE
* @Returns:
*    NONE
*/
void Print(){
  //FIX ME!
  int Index = Front;

  while(Index != Rear){
    cout<<Q[Index]<<" ";
    Index = ((Index + 1) % (ArraySize));
  }
  cout<<endl;
}
