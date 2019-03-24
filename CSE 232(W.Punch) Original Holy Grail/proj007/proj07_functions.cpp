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
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream;


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

 string pair_to_string(const pair<vector<double>,string> &p){
		ostringstream oss;	
		oss << std::fixed << std::setprecision(3); 
		for (auto elements = 0u; elements <= p.first.size()-1; ++elements){ // Loop through vector of elements as doubles
			oss << p.first.at(elements) <<" "; 			   //which are the key to the map. Send it on its marry 
										   // way to the ostream operator.
		
		}
		oss << p.second;// At the end send the 'value' of the pair which is the string to the ostream operator.
		return oss.str();
	}

void print_map(const map<vector<double>, string> &m,ostream &out){

	auto itr = m.begin(); // Itr is a pointer that points to the pair in the map. The pair is key(vector of doubles) and 
	while(itr != m.end()){ // the value(string)
		out << pair_to_string(*itr);
		out<<endl;
		itr++;
	}

}


double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){
	

	double sum=0;
	for(auto count = 0u; count <= feature_count; count++){ // Index into both vectors and return a signle value to compare against
		sum += pow(v1[count]-v2[count], 2); 	 // each other in the disatnce formula.
							// Sum is the distance between the current index of the the two vectors
	}

	double result = sqrt(sum);
	return result; 	
}
void  read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf){

	vector<double> vector_map_key;
	string temp_str;
	vector<string>temp_vector_str;					     
	while(getline(inf, temp_str)){ // Get every line from a input file and store it in a temp str. 				    
		 temp_vector_str = split(temp_str,',');//split that string by a char and store it into a vector of strings
							         
		for(auto element = 0u; element<temp_vector_str.size()-1; ++element){//loop through that vector of strings and convert 										             //those string elements into a double.
				double str_to_double = stod(temp_vector_str[element]);
				vector_map_key.push_back(str_to_double); 		// Push back those doubles into a vector 
				 
		}
		m[vector_map_key] = temp_vector_str.back(); // Construct a map from the vector of doubles
		vector_map_key.clear();// clear vector beacuase the value we just added is still at the back of the 'temp_vector_str'
	}

	

}


 map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k) {


	map<double,vector<double>> temp_map;
	vector<double> distances;
	for(const auto myPair : m){ // Iterates though the pairs of the map we previously created. 'MyPair' is that pair :) 
	 	double dist = distance(myPair.first,test,test.size());
		if(dist>0){
			//MyPair.first is the key of the previous map which is a element
			temp_map[dist] = myPair.first;			   //In a vector of doubles. We compare this element( a double) 
  			distances.push_back(dist);			   // to an element in the vector of doubles called test.
		} 	
    	}							   // We want the distance  between these two elements so we		
	std:: sort(distances.begin(),distances.end());		   //call our distance function. Store this distance as a key	
	map<vector<double>, string> k_nn;			   // in a map with the value as the element of the original vector 
	for(int i=0; i<k ; ++i){
		double d  = distances[i];
		vector<double> temp_vec = temp_map [d];
		string temp_str = m.at(temp_vec);
		k_nn[temp_vec] = temp_str;
	}						   
								   
 return k_nn;		
}

double test_one(const map<vector<double>, string> &m,pair<vector<double>, string> test, int k){

	double percentage=0.0;

	map<vector<double>,string> k_nn_map;
	k_nn_map = k_neighbors(m,test.first,k); // Every element in the k_nn_map is a pair of doubles as keys with strings as values

	for (auto element: k_nn_map){// compares a single element of the k_nn_map which is a pair whos value we look at/comapre by using 
		if(element.second == test.second)//.second against the value of the test which is a pair also with a vector of doubles
						 // as keys and the string as their value. 
		percentage += 1.0;		// if the values(strings) match then they are of the same classification. :)
						// And we keep track on this accuracy using the variable percentage
	}
	percentage = percentage/k;
	
	return percentage;

}

 double test_all(const map<vector<double>, string> &m, int k){
	double accuracy=0.0;
	double count =0.0;
	for(auto pair :m ){ // iterates through the map "m" and uses test one function to check the accuracy of the k closests neighbors 
		accuracy =test_one(m,pair,k);//on each pair in "m"
	 	count+=1;
	}
	return accuracy/static_cast<double>(m.size());
}