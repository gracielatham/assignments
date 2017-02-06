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
    }
    
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Head){
        Temp -> Next = Head;
      }

      Head = Temp;
      
    }
    
    void EndSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Tail){
        Temp -> Next = Tail;
      }
      
      Tail = Temp; 
   
    }
       
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