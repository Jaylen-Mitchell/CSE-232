/*	Project #1
 *	Setup Initial Variables
 *	Update them with correct calculations
 *	Print variables out
 *	Calculate Greenhouse Gases for any given set of MPG & Mileage
 */
#include <iostream>
#include <string>
#include <iomanip>
using std::cout; using std::cin; using std::endl; 

int main ()
{
float car_mpg =0.0;//Declared Initials 
float car_miles =0.0;
cin	 >>car_mpg>>car_miles;


float lbs_green_house_gas=0.0;//Declared Variables 
float lbs_green_house_gas2=0.0;
float lbs_green_house_gas3=0.0;
float car_mpg2=car_mpg+1.0;
float car_mpg3=car_mpg+5.0;


lbs_green_house_gas=((car_miles/car_mpg)*19.6*(100.00/98.65 ));//Calculated Variables
lbs_green_house_gas2=((car_miles/car_mpg2)*19.6*(100.00/98.65 ));
lbs_green_house_gas3=((car_miles/car_mpg3)*19.6*(100.00/98.65 ));
std::cout<<std::fixed;
std::cout<<std::setprecision(2);
cout << lbs_green_house_gas <<" "<< lbs_green_house_gas-lbs_green_house_gas2 <<" "<< lbs_green_house_gas-lbs_green_house_gas3;//Prints
}
