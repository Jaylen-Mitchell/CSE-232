#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;

#include "proj07_functions.h"

vector<string> split(const string &s, char delim){
// stackoverflow https://stackoverflow.com/questions/10058606/splitting-a-string-by-a-character
	string line;
	vector <string> elim_char_vector;
	std:: stringstream user_str(s);

		while(getline(user_str, line, delim)){ // We construct as stringstream  because getline expects it as its first 
						       // arguement 	
   			elim_char_vector.push_back(line);
		}
	
	return elim_char_vector;
}

string vector_to_string (const vector<string> &v){

	string vector_to_pretty_str="";

	for( auto &elements: v){

		vector_to_pretty_str+= (elements+ '\n');	
	}	
return vector_to_pretty_str;

}

void  read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf){

	vector<double> vector_map_key;
	string temp_str;
	string temp_vector_str;					     
	while(getline(inf, temp_str)){ // Get every line from a input file and store it in a temp str. 				    
		auto temp_vector_str = split(temp_str,',');//split that string by a char and store it into a vector of strings
							         
		for(unsigned element = 0; element<temp_vector_str.size()-1; ++element){//loop through that vector of strings and convert 										             //those string elements into a double.
				double str_to_double = stod(temp_vector_str[element]);
				vector_map_key.push_back(str_to_double); 		// Push back those doubles into a vector 
		}
	
	}

	m[vector_map_key] = temp_vector_str.back(); // Construct a map from the vecotr of doubles 

}






int main (){
  map<vector<double>, string> m;
  // ifstream f("little.txt");
  ifstream f("iris.data.txt");
  read_data(m, 4, f);
  print_map(m, cout);
  auto start = m.begin();
  auto follow = next(start, 1);
  cout << distance(start->first, follow->first, 4) << endl;
  auto result = k_neighbors(m, start->first, 3);
  cout << "test: " << pair_to_string(*m.begin() ) << endl;
  print_map(result, cout);
  cout << "Accuracy for first: "<<test_one(m, *(m.begin() ), 3) << endl;
  cout << "Accuracy for all: " << test_all(m, 3) << endl;
}
