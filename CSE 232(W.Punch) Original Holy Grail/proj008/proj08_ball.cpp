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
#include "proj08_ball.h"
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream;

// Things to note*
// Whenever I create a ball object without arguments it will defualt to the intial conditions
// If I create an object ball with given parameters it will default those given parameters I fed it.  

Ball:: Ball(double m, TwoD pos, TwoD speed, double r){

	 mass = m;
  	 coords = pos;
  	 velocity = speed;
  	 radius = r;
}

string Ball:: to_string (){

	ostringstream oss;				// Set ostream operator to have a set percision of two.
	oss << std::fixed << std::setprecision(2); 
	oss << mass <<","<< " "<< "("<< coords.x <<", "<< coords.y<< ")"<<"," 
	<< " "<< "("<< velocity.x<<", "<< velocity.y<<")"<<","<<" " <<radius;
							// Use pointer to point to the double x,y in the struct and send them to the 								//OS to convert them to a string with two decimal places.
					     
	return oss.str();
}



bool Ball:: contact_ball(Ball object_ball_two){ 

	
 	
	double object_ball_distance_x = (this->coords.x-object_ball_two.coords.x); // Calculate the diff of the x coords from the
										   // two objects and store as double
	double object_ball_distance_y = (this->coords.y-object_ball_two.coords.y);// Calculate the the diff of the y coords
	
	double ball_distance = sqrt(pow(object_ball_distance_x,2)+ pow(object_ball_distance_y,2));
	
	double ball_radius   = (this->radius + object_ball_two.radius);
	
	if(ball_distance < ball_radius){
		return true;
		}

	else{
	return false;
	}

	
}

bool Ball:: contact_wall(long xdim, long ydim){

	if(coords.x-radius <=0){
		return true;
	 }	
	else if (coords.y-radius <= 0){
		return true;
	  }
	else if (coords.x+radius >= xdim){
		return true;
	  }
	else if (coords.y+radius >= ydim){

		return true;
	  }
	
		
return false;
}


TwoD Ball:: update_velocity_wall(long xdim, long ydim){
	
	TwoD update_velocity_vector;

	if(coords.x-radius <=0){
		update_velocity_vector.x = this -> velocity.x *-1;
		update_velocity_vector.y = this -> velocity.y;
		return update_velocity_vector;
	}	
	else if (coords.y-radius <= 0){
	  	update_velocity_vector.y = this -> velocity.y *-1;
		update_velocity_vector.x = this -> velocity.x;
		return update_velocity_vector;
	}
	else if (coords.x+radius >= xdim){
		update_velocity_vector.x = this -> velocity.x *-1;
		update_velocity_vector.y = this -> velocity.y;
		return update_velocity_vector;
	}
	else if (coords.y+radius >= ydim){
		update_velocity_vector.y = this -> velocity.y *-1;
		update_velocity_vector.x = this -> velocity.x;
		return update_velocity_vector;
	}
return update_velocity_vector;	
}
	

TwoD Ball:: update_velocity_ball(Ball object_ball_two){

	
	double mass_calculation = (2*object_ball_two.mass)/(this->mass+object_ball_two.mass);
	TwoD velocity_vector_one_diff  =  this->velocity.diff(object_ball_two.velocity);
	TwoD coordinate_vector_two_diff = this->coords.diff(object_ball_two.coords);
	double Dot_product_calcultion = velocity_vector_one_diff.dot_product(coordinate_vector_two_diff);
	double coordinate_mag_squared = this->coords.diff(object_ball_two.coords).magnitude_squared();
	double scalar_dot_coord_calculation = Dot_product_calcultion/coordinate_mag_squared;
	double scalar_mass_dot_coord_calc   = mass_calculation * scalar_dot_coord_calculation;
	TwoD new_vector = coordinate_vector_two_diff.mult(scalar_mass_dot_coord_calc);
	TwoD vector_intial = this->velocity.diff(new_vector);
	TwoD vector_prime = vector_intial;

	return vector_prime;
} 
