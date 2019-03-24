#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
using std::cout; using std::cin; using std::endl; 

int divisor_count_function (int n){ // This logic will need to be excuted in a                                  repated loop to check the divisor count of the 
int divisor_count=0;		   // numbers less than the original "n." Why not                                   make it a function? :)	
for (long i=1; i<=n; i++){
    if (n % i == 0)
    divisor_count+=1;

}

return divisor_count;

}

int main () {
int user_int=0;
cin >> user_int;

if ( user_int < 0 ) // We dont want negative inputs from the user!
cout << "Error"<<endl;

int y= divisor_count_function(user_int);

for(long j=1; j<= user_int-1; j++){

    int x = divisor_count_function(j);
  
    		if (x>=y){// We want compare each int all the way until n-1
	
    		cout << "False" <<" "<<  user_int<< " " << j <<" " << x <<endl; //                                    If their exists a number that has a greater 
		break;					// divisor count than the orginal "n" stop the 
							// loop and print out that value. Do nothing else!

        
		}

    		else if (x<y && j== user_int-1){ //Says:"hey I went through all the                                       values and checked their divisor counts
		cout << "True" <<" "<<  user_int <<" " << y <<endl;//and I didnt find                                      any of them that had more than the orginal"n"
    								  // Additionally it says "Im also looking                                      at the last number"	// before "n"	and it                                      too does not have a divisor count greater//                                     than the orginal "n"

		}
		
		
		

   
}
return 0;

}
		