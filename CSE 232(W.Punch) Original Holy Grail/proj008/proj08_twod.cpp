#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ios>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream> 
#include <sstream>
#include <map>
#include <utility>
#include "proj08_twod.h" 
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream;


TwoD::TwoD(double xval, double yval){
	x=xval;
	y=yval;
}
string TwoD:: to_string(){
	
	ostringstream oss;	// Set ostream operator to have a set percision of two.
	oss << std::fixed << std::setprecision(2); 
	oss << "("<< this ->x << ","<< " "<< this ->y <<")"; // Use pointer to point to the double x,y in the struct and send them to the OS to convert
					     // them to a string with two decimal places.
	return oss.str();

}

TwoD TwoD::diff(TwoD two_d_vector){ // Pass TwoD string with x and value into function
 			      // Convert string to double and calculate the differnece between the two values	
			      // Return difference as a TwoD string 
	
	TwoD vector_difference;
	vector_difference.x =  this ->x - two_d_vector.x;// this refers to your values from the data members. ."something"
	vector_difference.y =  this -> y -two_d_vector.y; // refers to the values of the type you create. 
	
	return vector_difference;
}


TwoD TwoD::mult(double user_double){


TwoD vector_mult;
	vector_mult.x = this -> x * user_double;
	vector_mult.y = this -> y *user_double;
	
	return vector_mult;

}


double TwoD::dot_product(TwoD vector_one){

	TwoD vector_dot_sum;
	double vector_dot_product_result;
	vector_dot_sum.x = (this ->x * vector_one.x) ;
	vector_dot_sum.y = (this ->y * vector_one.y );
	
	vector_dot_product_result = (vector_dot_sum.x + vector_dot_sum.y);
	return vector_dot_product_result;

}

double TwoD:: magnitude_squared(){

	double magnitude; 
	magnitude = pow(x,2)+pow(y,2);
	



	return magnitude;

}