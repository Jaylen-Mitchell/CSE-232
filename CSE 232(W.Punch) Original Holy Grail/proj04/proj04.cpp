/*    Project #4
 *    Setup Initial Variables and bool functions
 *    Update them with correct methods
 *    return bools within function to be sent to main
 *    
 */


#include<iostream>
#include <algorithm>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include<cmath>
using std::sqrt; using std::ceil; using std::round;
#include<string>
using std::string; using std::stol; using std::to_string; using std:: reverse;
// add whatever header stuff you need, delete anything you don't
// up to you


bool is_prime(long n)
{
  if (n < 2) return false;
  for(long i=2; i<= sqrt(n); i++) {
    if ((n%i) == 0) return false;
  }
  return true;
}


bool is_semiprime(long n)
{
    for(int i = 2 ; i <= sqrt(n) ; i++ )// starts at two and goes all the way until we have a factor of 2(i<= n/2)
    {
           if((n%i)==0)// checks for remainder of "0" to accuire a factor of whatever the user picks for "n"
            
                if(is_prime(i)and is_prime(n/i))// if "i" is prime  and n/i is also prime we have found a semiprime factor
               
                  return true;
                  
                  
               
               else
                return false;
               
          }           
    }
 
 
long reverse_num(long n)
{ 

 
 string str_n = to_string(n);
 reverse( str_n.begin(),str_n.end());
 
 
 
 return stol(str_n);
 
} 
 
    


bool is_palindrome(long n)    
{

    if (n == reverse_num(n))
    return true;
    
    
    else 
    return false;


}





bool is_emirp(long n)
{

if (is_palindrome(n)== true)
return false;

if (is_prime(n))
    if (is_prime(reverse_num(n)))
    return true;


}




bool is_emirpimes(long n)
{

if (is_semiprime(n) and is_semiprime(reverse_num(n)) and !is_palindrome(n))
    return true;





        

}











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
    
