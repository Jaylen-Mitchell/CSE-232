#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
// any other includes you need
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ios>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream> 
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline;


#include "proj06_functions.h"

// your functions after this

string to_binary(int user_int){
	int extra_zeros_needed=0;
	int length =0;
	int remainder =0;
	//char ch = (char)user_int;
	string initial_binary_str="";
	string complete_binary_str="";
	

					// Continously divide user_int by two. If the remainder is equal to zero add zero to 						//str_binary_str.Else add one to str_binary_str		
	if(user_int<0 || user_int>255){
	complete_binary_str="00000000";
	return complete_binary_str;
	}		        
	
	for(; user_int!=0; ){
		remainder = user_int % 2;
		user_int /= 2;
		if(remainder == 0)
			initial_binary_str+= '0';
		else{
			initial_binary_str+= '1';
		}
	

	}
	length 		   = initial_binary_str.length();
	extra_zeros_needed = 8-length;
	string last_binary_str(extra_zeros_needed,'0');
	complete_binary_str = initial_binary_str+last_binary_str;

	
	std::reverse(complete_binary_str.begin(),complete_binary_str.end());// Reverse elements in string 


return complete_binary_str;

}



int next_val(const vector<int> &v, const string &rule_binary_string){



	if(v[0]==1 && v[1]==1 && v[2]==1) //7
		return rule_binary_string[0] -'0';
	else if(v[0]==1 && v[1]==1 && v[2]==0) //6
		return rule_binary_string[1] -'0';
	else if(v[0]==1 && v[1]==0 && v[2]==1) //5
		return rule_binary_string[2] -'0';
	else if(v[0]==1 && v[1]==0 && v[2]==0)//4
		return rule_binary_string[3] -'0';
	else if(v[0]==0 && v[1]==1 && v[2]==1)//3
		return rule_binary_string[4] -'0';
	else if(v[0]==0 && v[1]==1 && v[2]==0)//2
		return rule_binary_string[5] -'0';
	else if(v[0]==0 && v[1]==0 && v[2]==1)//1
		return rule_binary_string[6] -'0';
	else if(v[0]==0 && v[1]==0 && v[2]==0)//0
		return rule_binary_string[7] -'0';
	return '0';

}
vector<int> one_iteration(const vector<int> &v, const string &rule_binary_string){

	int num=0;
	vector<int> next_itr;
	//cout << " last index " << v.size() -1 << endl;

	for (unsigned index=0; index<v.size()-1; index++){
		if (index == 0){

			num = next_val({0, v[index], v[index+1]},rule_binary_string);
		}
	
            
	
		else{
            //cout<<"Index in else "<<index<<endl;
		     num = next_val({v[index-1], v[index], v[index+1]}, rule_binary_string);            
		     //if(num == 48){
	         //cout<<"Second Num " <<num<<endl;
	         //cout<< v[index-1]<<" "<<v[index]<<" "<<v[index+1]<<endl;
	         //cout<< "V Size"<<v.size()<<endl;
	         //cout<< "V Index +1"<<v[index+1]<<endl;
		     //}
		}
	    //cout << "Index Change "<< index<<endl;
		next_itr.push_back(num);
		

	}	
	

            //cout<<"Index + 1 "<<index+1<<endl;
			next_itr.push_back( next_val({v[v.size()-2], v[v.size()-1], 0}, rule_binary_string));
			//cout<<"Num"<<num<<endl;
	return next_itr;

}


string vector_to_string (const vector<int> &v){

	string vector_to_pretty_str="";

	for( auto &elements: v){

		vector_to_pretty_str+= (elements + '0');
		vector_to_pretty_str+=',';

	}
	vector_to_pretty_str.pop_back();


	
return vector_to_pretty_str;
}


void read_vector(vector<int> &v, string fstring){
	string line;
	int  value;
	std::ifstream infile(fstring);
	bool flag = false;

	if(v.size()==0){
		if(infile.is_open())
			while(infile >> value){
				flag = true;
				v.push_back(value);
			}
		}
	else{
		flag = false;
		
	}
		
}	

		


// a freebie!
// takes in a vector of 0,1
// outputs a string of '_' or '*'
//string pretty_print(vector<int> & v){
 // ostringstream oss;
 // transform(v.begin(), v.end(), ostream_iterator<char>(oss),
//	    [] (int i) {
//	      return (i==0) ? '_' : '*';
//	    }
//	    );
//    return oss.str();
//}
