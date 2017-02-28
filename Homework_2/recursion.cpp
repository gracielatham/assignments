#include <iostream>

void A (char ch){
  if(('A'<= ch) && (ch <= 'H')){
    A(ch-1);
    cout<<ch<<endl;
  }else{
    cout<<endl;
  }
}

int B (int n){
  if(n==0)
    return 1;
  else{
    cout<<n<
    <endl;
    return n * B(n-1);
  }
}

int C (int n){
  if(n<2)
    return 0;
  else
    cout<<n<<endl;
    return (1 + C(n/2));
}

int D (int n){
  if(n<0)
    return D(-n);
    if(n<10){
      cout<<n<<endl;
      return n;
    }else{
      cout<<n<<endl;
      return D(n/10);
  }
}

int NumDigits(int num){
    // Returns the "length" of an integer
}

int MyPow(int base, int exp)
    // Returns base^exp


)

int SumArray(int A[], int n)
    // Return sum of A[0] + A[1] + … + A[n-1]


)

int main() {
    
}
