#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
#include <ios>
using std::cout; using std::cin; using std::endl; using std::boolalpha;

//Project # 3



bool IsPrime(long n)
{	// Given:   num an integer > 1
	// Returns: true if num is prime
	// 			false otherwise.
	if(n == 2) return true;
	if(n%2 == 0) return false;  
	for (long i=3; i<= sqrt(n); i+=2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	
	return true;	
}


long biggest_prime (long n){
//bool isPrimeFunc = false;
	long potential_prime_factor=0;
	long biggest_prime_num=2;
	//long real_prime=0;
	//bool isPrimeFunc = IsPrime(long n)
	 long d=2;
	 /*
	 for(long i = n; i > 1; i--){
	 	if(IsPrime(i) && (n % i == 0)){ //Back up code for simple way to find                                    biggest prime. start from n and subtract "i"
 	 		return i; 		//      by two each time until you stumble across                              //         biggest prime :)
 	 					// We subtract by two each time to find prime numbers                               easier. They are more likely to be odd :P
	 	}				// When you think it about it... why start from i=1 when                             you can start at n and go backwards
	 		
	 }
	 */
	 while(n != 1){
	 	if(IsPrime(d)){
	 		potential_prime_factor = d; 
	 	}
	 	if(n % d == 0){
	 		n /= d; 
	 	} else {
			if(d == 2){
				d++; 
			} else {
				d+=2;
			}
		}
	 }
	 
	 
	return potential_prime_factor;
}



long divisor_sum_function (long n){ // This logic will need to be excuted in a repated loop to sum the divisors
long divisor_sum=0;		   // numbers less than the original "n." Why not make it a function? :)	
for (long i=1; i<=sqrt(n); i++){
    if (n % i == 0){
    	divisor_sum+=i;
    	divisor_sum+=n/i; 
    }
}
return divisor_sum;

}

long k_hyperperfect(long n, long k_max){
	for (long temp_kmax=1; temp_kmax<=k_max; temp_kmax++){
		long div_sum  = divisor_sum_function(n);
		long k_perfect_formula = 1+temp_kmax*(div_sum-n-1);
		if (k_perfect_formula == n){ 
			//cout <<" This number is"<<k_max<<"perfect"<<endl;
			return temp_kmax;
	
		}		
	}	     
	return 0;
}




bool b_smooth(long n, long b){

if (biggest_prime(n)<= b){ //calls biggest prime function to compare values 

	return true;
}
else{
	return false;
} 

}


int main(){


long user_long =0;          // Main calls function cout's to display variables 
long user_prime_num_choice=0;
long user_k_max=0;

cin >> user_long >> user_k_max >> user_prime_num_choice; 
long bp = biggest_prime(user_long);

long ds = divisor_sum_function(user_long);
bool b_num_smooth = b_smooth(user_long,user_prime_num_choice);
long k_hp = k_hyperperfect(user_long,user_k_max);

cout << boolalpha;
cout << bp <<" "<< ds <<" "<< k_hp<<" "<<  b_num_smooth << endl;





return 0;
}


