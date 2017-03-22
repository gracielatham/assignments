/**
* @ProgramName: Program-3
* @Author: Gracie Latham
* @Description: 
*     This Program implements a simple calculator
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 3/20/2017
*/

#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class Queue{
  private:
  
  int ArraySize;
  char *Q;
  int Front;
  int Rear;
  int NumItems;
  
  public:
  
  /**
  * @FunctionName: Queue
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial queue size
  * @Returns:
  *    void
  */
  Queue(int insize){
    ArraySize = insize;
    Q = new char[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void Push(char c){
    if(Full()){
      cout<<"Queue Full!"<<endl;
      return;
    }
    Q[Rear] = c;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return;
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char Pop(){
    if(Empty()){
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
  /**
  * @FunctionName: printQueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void PrintQueue(){
    for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%ArraySize){
      cout<<Q[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool Empty(){
    return (NumItems == 0);
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool Full(){
    return (NumItems == ArraySize);
  }
};



/**
* @FunctionName: Stack
* @Description: 
*     Implementation of a char stack
*/
class Stack{
  private:
  
  char *S;
  int top;
  int size;
  
  public:
  
  /**
  * @FunctionName: Stack
  * @Description: 
  *     Class constructor
  * @Params:
  *    int insize - initial stack size
  * @Returns:
  *    void
  */
  Stack(int insize){
    size = insize;
    top = -1;
    S = new char[size];
  }
  
  /**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
  void push(char c){
    if(!full()){
      S[++top] = c;
    //}else{
    //  cout<<"Stack Overflow!"<<endl;
    }
  }
  
  /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
  char pop(){
    if(!empty())
      return S[top--];
    else
      return -1;
  }
  
  /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  void printStack(){
    for(int i=top;i>=0;i--){
      cout<<S[i]<<" ";
    }
    cout<<endl;
  }
  
  /**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  bool empty(){
    return top == -1;
  }
  
  /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
  bool full(){
    return top == size-1;
  }
};

class Convert{
private:
   Stack *S;
   Queue *Q;
public:
  Convert(){

    S = new Stack(20);
    Q = new Queue(20);
  }
  
  void tempFunc(){
    char temp;
    int i;
    string infix;
     
    for(int i=0;i<infix.length();i++){
      S->push(infix[i]);
    }
    
    while(!S->empty()){
      temp = S->pop();
      cout<<temp;
    }
  }
};

class Calculator{
private:
  Queue *Q;
  Stack *S;
  int Size;
  string infix;
  string postfix;
  char ch = '*';
  int val;
  int oper;
  void InfixToPostfix(){
    switch(ch){
    case '+':
    case '-':
      val = 1;
      break;
    case '*':
    case '/':
    case '%':
      val = 2;
      break;
    case '(':
    case ')':
      val = 3;
      break; 
    default:
      val = -1;
  }
    if(infix.length() == 0){
      cout<<"Error: infix not set.";
      return;
    }
    for(int i=0;i<infix.length();i++){
      S->push('(');
      S->push(')');
      S->push(infix[i]);
    }
  while(!S->empty()){
    if(ch = val){
    S->push(ch);
    ch = val; 
  }else if(ch = '('){
    S->push(ch);
  }else if(ch != val){
    while(val >= oper){
    S->pop();
    S->push(ch);
  }
  }else if(ch = '('){
    while(ch != ')'){
      S->pop();
    }
  }
 }
      postfix += S->pop();
    }
    
  int EvaluatePostfix(){
    Queue *Q;
    Stack *S;
    string postfix; 
    int val;
    char ch;
    for(int i=0;i<postfix.length();i++){
    while(!Q->Empty()){
    if(ch = val){
      Q->Push(ch);
    }else{
      Q->Pop();
      Q->Pop();
      Q->Push(ch);
    }
    if(Q->Empty()){
      cout<<postfix<<endl;
    }
  }
    }
    return 99;
  }
public:
  Calculator(){
    Queue *Q;
    Stack *S;
    infix = "";
    postfix = "";
  }
  int ProcessExpression(string exp){
    int answer = 0;
    Q = new Queue(exp.length()+2);
    S = new Stack(exp.length()+2);
    infix = exp;
    cout<<infix<<endl;
    InfixToPostfix();
    answer = EvaluatePostfix();
    delete Q;
    delete S;
    return answer;
  }

};






int main(){
  ifstream infile;
  ofstream outfile;
  infile.open("exp.txt");
  outfile.open("output.txt");
  
  string infix;
  string postfix; 
  int i;

  cout<<"Expression"<<endl;

  Calculator C;
  
  while(i <= 8){
  infile>>infix; 
  outfile<<infix<<"="<<postfix<<endl; 
  i++;
 }
  
  infile.close();
  outfile.close(); 
}

