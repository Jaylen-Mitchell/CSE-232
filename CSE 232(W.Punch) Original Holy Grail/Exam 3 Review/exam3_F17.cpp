#include<iostream>
using std::cout; using std::endl;

long* fn1(long &v1, long *v2){
  long *t = v2;
  v1 = v1 + *t;
  *v2 = v1 - *t;
  return t;
}

bool fn2(long &v1, long &v2){
  size_t result=0;
  if (v1 > v2){
    long t = v1;
    v1 = v2;
    v2 = t;
  }
  for(long i=v1; i<v2; i+=2)
    ++result;
  return (result > v2) ? true : false;
}

int main (){
  long arg1=10, arg2=20;
  auto fn1_result = fn1(arg1, &arg2);  // Line 1
  cout << fn1_result << endl;          // Line 2
  cout << arg1 << endl;                // Line 3
  cout << arg2 << endl;                // Line 4

  arg1=10;
  arg2=20;
  auto fn2_result = fn2(arg1, arg2);  // Line 5
  cout << fn2_result << endl;         // Line 6
  cout << arg1 << endl;               // Line 7
  cout << arg2 << endl;               // Line 8
}
  
  
