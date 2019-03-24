/*	Project #2
 *	Setup Initial Variables
 *	Update them with correct calculations
 *	Print variables out
 *	Calculate GCD and totative 
 */





#include <iostream>
using std::cout; using std::cin; using std::endl;

int gcd(int first_number, int second_number) {

	if (first_number < second_number) {
        std::swap(first_number, second_number);
    }

	
  while (second_number != 0)  {
    int t = second_number;
    second_number = first_number % second_number;
    first_number = t;
  }
  return first_number;
}




long phi_function(long n){
long phi_count=0;
	 for(long i=1; i<=n; i++){
		 long gcd_result=gcd(i,n);
		 
		 if (gcd_result==1){
		 ++phi_count;
		 cout <<i <<" ";
			}			
		}
		cout<<endl;
return phi_count;
}




int main (){


long  second_number;
long first_number;
long n;

/*if (first_number < second_number){
	cin >> first_number >> second_number;
}

if(first_number > second_number){
	second_number=first_number;
	cin >> second_number >> first_number;
	
}*/

cin >> first_number >> second_number;
cin >> n;

if(first_number < 0) {
	cout <<  "Error" <<endl;
	return 0;
}


if(second_number < 0) {
	cout <<  "Error" <<endl;
	return 0;
}

long gcd_output=gcd(first_number,second_number);
cout<<gcd_output<<endl;
long phi_output=phi_function(n);
cout<<phi_output<<endl;//Displays output

return 1;
}
