#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
#include <ios>
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::stringstream;

// meta, strictly increase
// plain, non-strictly increase
// kata, strictly decrease
// nialp, non-strictly decrease
// non, none of the above


// new_str takes gives the starting index of base_vals and stops at user give base_num index
// By using a sub.str we can get the max range of values to use for the given base_num	



// and then set a variable equal to new_str.find(num_str[str_index+1])
// We can compare the current value we are looking at and the next one
// new_str.find(num_str[str_index]) returns an int so the variable type  
// needs to be an int



const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";




bool metadrome(string num_str, int base_num){

int    current_num  = 0;
int    next_num     = 0;
string new_str      = base_vals.substr(0, base_num);
// new_str takes gives the starting index of base_vals and stops at user give base_num index
// By using a sub.str we can get the max range of values to use for the given base_num	
// and then set a variable equal to new_str.find(num_str[str_index+1])
// We can compare the current value we are looking at and the next one
// new_str.find(num_str[str_index]) returns an int so the variable type  
// needs to be an int

	for(int str_index=0; str_index < num_str.length()-1; str_index++){ //Step through each index and compare the chars against one another
		current_num  = new_str.find(num_str[str_index]);
		next_num     = new_str.find(num_str[str_index+1]);
		if (current_num == string::npos){
		return false;
		}
		//current_num= str.find()num_str[str_index-1];			 	
		//cout << "Current number"<<current_num<<endl;	
		//cout << "next number"<<next_num<<endl;	           
		else if (next_num <= current_num ){		   			
		return false;
		}
		
	
    }
return true;
}


bool plaindrome (string num_str, int base_num){
int    current_num  = 0;
int    next_num     = 0;
string new_str      = base_vals.substr(0, base_num);
// new_str takes gives the starting index of base_vals and stops at user give base_num index
// By using a sub.str we can get the max range of values to use for the given base_num	
// and then set a variable equal to new_str.find(num_str[str_index+1])
// We can compare the current value we are looking at and the next one
// new_str.find(num_str[str_index]) returns an int so the variable type  
// needs to be an int

	for(int str_index=0; str_index <num_str.length()-1; str_index++){ //Step through each index and compare the chars against one another
		current_num  = new_str.find(num_str[str_index]);
		next_num     = new_str.find(num_str[str_index+1]);
		
		if (current_num == string::npos){
		return false;
		}
		        
		else if (next_num < current_num){		   									   	
		return false;
		}
		
	
    }
return true;
}


bool katadrome(string num_str, int base_num){


int    current_num  = 0;		    
int    next_num     = 0;
string new_str      = base_vals.substr(0, base_num);
// new_str takes gives the starting index of base_vals and stops at user give base_num index
// By using a sub.str we can get the max range of values to use for the given base_num	
// and then set a variable equal to new_str.find(num_str[str_index+1])
// We can compare the current value we are looking at and the next one
// new_str.find(num_str[str_index]) returns an int so the variable type  
// needs to be an int
	for(int str_index=0; str_index <num_str.length()-1; str_index++){ 
		current_num  = new_str.find(num_str[str_index]);
		next_num     = new_str.find(num_str[str_index+1]);        
		
		if (current_num == string::npos){			
		
		return false;
		}
		
		
		else if (next_num >= current_num){		   									   	
		return false;
		}
		
	
    }
return true;
}



bool nialpdrome(string num_str, int base_num){
int    current_num  = 0;				// new_str takes gives the starting index of base_vals and stops at user give base_num index
int    next_num     = 0;				// By using a sub.str we can get the max range of values to use for the given base_num
string new_str      = base_vals.substr(0, base_num); 
	for(int str_index=0; str_index <num_str.length()-1; str_index++){ 
									//Step through each index and compare the chars against one another
		current_num  = new_str.find(num_str[str_index]);	  
									// If we set a variable equal to new_str.find(num_str[str_index])
		next_num     = new_str.find(num_str[str_index+1]);        
									// and then set a variable equal to new_str.find(num_str[str_index+1])
									  // We can compare the current value we are looking at and the next one
									  // new_str.find(num_str[str_index]) returns an int so the variable type 
									  // needs to be an int
		if (current_num == string::npos){			
		return false;// Condition check to see if the number or letter is in line with the given base. For example if the given base is 16 and the 
		}	     // user string is '123ab' then both 'a' and 'b' dont belong 
		
		else if (next_num > current_num){		   									   	
		return false;
		}
		
	
    }
return true;
}


string classify(string num_str, int base_num){

string str_num_type_meta = "metadrome";
string str_num_type_palin = "plaindrome";
string str_num_type_keta  = "katadrome";
string str_num_type_neialp = "nialpdrome";
string str_non_drome = "nondrome";



	if(metadrome(num_str,base_num )== true){ // Calls functions to  returns string(which be outputed to dispaly terminal aka cout) based on whether 						//nor not they returned true.
		return str_num_type_meta;}
	else if (plaindrome(num_str,base_num) ==true){
		return str_num_type_palin;}
	
	if(katadrome(num_str,base_num )== true){
	return str_num_type_keta;}
	else if (nialpdrome(num_str,base_num) ==true){
		return str_num_type_neialp;}
	else{
	return str_non_drome;
	}

}


int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " " 
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
    








