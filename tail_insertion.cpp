/**
* Homework 1 - EndSert Method
* Gracie Latham
* Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date: 10 02 2017
*/

#include <iostream>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
      Tail = NULL; 
    }
    
  /**
* FunctionName: FrontSert
* Description: 
*     Inserts a value to the front of the list 
* Params:
*    int x - Represents values inputed into the front of list 
* Returns:
*    void
*/
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Head){
        Temp->Next = Head;
      }

      Head = Temp;
      
    }
   
  /**
* FunctionName: EndSert
* Description: 
*     Inserts values into end of the list 
* Params:
*     int x - Represents values inputed into the end of list
* Returns:
*    void
*/
void EndSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(!Head){
       Head = Temp; 
      }else{
          Node *Curr = Head;
          Node *Prev = Head;
          
          Prev = Curr;
          Curr = Curr->Next;
          
          Curr->Next = Temp; 
          Temp->Next = Tail; 
      }
        
       Tail = Temp;
   
     }
  /**
* FunctionName: PrintList
* Description: 
*     Prints list of values into output
* Params:
*     None
* Returns:
*    void
*/  
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        Node *Temp = Head;
        while(Temp != NULL){
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
    }

};


int main() {
    srand(97097807);
    List L;
    
    for(int i=0;i<10;i++){
      L.FrontSert(rand()%100);
    }
    
    for(int i=0;i<10;i++){
      L.EndSert(rand()%100);
    }
    
    L.PrintList();
    
    
    return 0;
}
