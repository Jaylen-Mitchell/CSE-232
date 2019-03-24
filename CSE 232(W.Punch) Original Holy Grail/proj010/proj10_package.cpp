#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream> 
#include <sstream>
#include <map>
#include <utility>
#include "proj10_package.h"
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream; 


	ostream& operator<<(ostream& out_stream, Package& pack){
		out_stream << pack.weight_ <<":"<<pack.priority_; 
		return out_stream;	
	}	



	bool package_compare(const Package &p1, const Package &p2){
	
		double p1_ratio =  (double) p1.priority_/p1.weight_ ;
		double p2_ratio =  (double) p2.priority_/p2.weight_;
		if(p1_ratio> p2_ratio){
			return true;
		}
		else if(p1.priority_/p1.weight_ == p2.priority_/p2.weight_ ){
			if(p2_ratio > p1_ratio)
				return false;
		}		
		return false;	
	}

						





