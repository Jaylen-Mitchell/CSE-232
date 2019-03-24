#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include<cmath>
using std::sqrt; using std::ceil; using std::round;
#include<string>
using std::string; using std::stol; using std::to_string;
// add whatever header stuff you need, delete anything you don't
// up to you


// your function defintions here


int main (){
  cout << boolalpha;

  int test_case;
  cin >> test_case;

  switch (test_case){

  case 1 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_prime(num) << endl;
    break;
  } // of case 1

  case 2 : {
    long num;
    while (cin >> num)
      cout << num << ":" << reverse_num(num) << endl;
    break;
  } // of case 2

  case 3 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_palindrome(num) << endl;
    break;
  } // of case 3   

  case 4 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_emirp(num) << endl;
    break;
  } // of case 4

  case 5 : {
    long num;  
    while (cin >> num)
      cout << num << ":" << is_semiprime(num) << endl;
    break;
  } // of case 5

  case 6 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_emirpimes(num) << endl;
    break;
  } // of case 6    
    
  } // of switch
} // of main
    
