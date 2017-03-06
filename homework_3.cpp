/**
* Homework 3 - Fix Print Function
* Gracie Latham
* Description: 
*     This program inserts values into a queue using functions
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date: 01 03 2017
*/

/**
* FunctionName: Print
* Description: 
*     Insert an if statement to look for when Index is equal to the rear of the queue.
* Params:
*    NONE
* Returns:
*    NONE
*/
  void Print(){

    int Index = Front;
    
    while(Index != Rear){
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
    }
    
    if(Index = Rear){
      Index = ArraySize;
      cout<<Q[Index]<<" ";
    }
   
    cout<<endl;
 }
