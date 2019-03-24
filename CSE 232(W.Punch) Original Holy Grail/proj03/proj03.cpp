/*    Project #3
 *    Setup Initial Variables and bool functions
 *    Update them with correct methods
 *    return bools within function to be sent to main
 *    
 */


#include<iostream>
#include <cmath>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
// add any other includes you like.

// functions go here

bool is_prime(long n)
{
  if (n < 2) return false;
  for(long i=2; i<= sqrt(n); i++) {
    if ((n%i) == 0) return false;
  }
  return true;
}




bool is_powerful(long n)
    {
		bool is_prime_fun = is_prime(n);
        if (is_prime_fun == true) 
        {
        	return false;
		}	
                
   
		for(int i = 2; i <= n - 1; i++)//
			{
				long factor=i;// Intialize a factor variable to update for every "i"
				if((n % i)== 0) // As you check from [i,n] if "i" divided by n does have remainder  toss that into the factor variable
				{
					if(!is_prime(factor)){
						continue;
					}
				
					if (n % (factor*factor)!=0)//further check factor to see if it's powerful by squaring it 
					{
						return false;
					}	
								
								
				}	
			}
		return true;	
			
	}		
			
			
		

bool is_perfect_power(long n)

   {
        long base_limit = 100000;
        for (int i = 2; i <= base_limit; i++)// This for loop ones once and then follows the second for loop logic.
        {
            for (int j = 2; pow(i,j) <= n; j++){// This loop will check increasing powers starting at base 2.  
            	int x =(pow(i,j)); //If it does not equal the user's n value it will go back to the first for statment and increase	   
            	if (x == n){// and increase the base. this process will repeat until the n value is matched
            	return true;
            	}
            }            
            
            // continue;                       
                  
                        
					
            
             
                   
					 
           }
           return false; 
        }
      
  
        

bool is_achilles(long num)

    {
    bool powerful_fun = is_powerful(num);
    bool perfect_pwr_fun = is_perfect_power(num);

        {
        if ((powerful_fun == true) and (perfect_pwr_fun) == false)
            return true;
                   
			else 
                return false;

		    }

         }                                                                                	

    
  
  

    
    
    

    
 



 











// main is below. You cannot modify main
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
      cout << num << ":" << is_powerful(num) << endl;
    break;
  } // of case 2

  case 3 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_perfect_power(num) << endl;
    break;
  } // of case 3   

  case 4 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_achilles(num) << endl;
    break;
  } // of case 4
    
  } // of switch
} // of main
    
