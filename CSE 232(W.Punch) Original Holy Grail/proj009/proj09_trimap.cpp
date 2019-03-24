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
#include "proj09_trimap.h"
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream; 


	TriMap::TriMap(const Element& object_element){
	sz_ = 1;   
	vec_.push_back(object_element);
}

	ostream& operator<<(ostream& out_stream, const TriMap& tri_map_object){//TriMap contains a vector of elements from the object 
		unsigned int num_of_elements_vec = tri_map_object.vec_.size();//Element that we are sending to an ostream pipe.
		for( auto elements: tri_map_object.vec_){//Since we have already sent the data members from element in a previous 
			if (num_of_elements_vec >1){// ostream opereator we don't have to repeat those steps.
				out_stream << elements<<", ";// We set up a variable to reperesent the number of elemnts in the vector
			}				     // As we step through those elemnts if there is more than one we need a 	
			else if(num_of_elements_vec <= 1){  // ", " between each element. We break this into different cases.
				out_stream << elements;	   //A case where we only have one element and a case where we have more than one
			}
			num_of_elements_vec--;// Start from max num of present elements and work our way down  							
		}							
		return out_stream;					
}


	ostream& operator<<(ostream& out_stream, const Element& object_element){ //Object element has a string key, string value and a 
		out_stream << object_element.key_ <<":"<<object_element.value_ <<":"<<object_element.index_;// long index. Not		
		return out_stream;								//much to do here.Send those data members
}												// to an out stream 

TriMap::TriMap(initializer_list<Element> initial){
	copy(initial.begin(), initial.end(), back_inserter(vec_));// take the initial contents in the intial list and copy them
	sz_ = initial.size();					  // 
}

size_t TriMap::size(){

	return sz_;

} 


bool TriMap::insert(string key, string value ){
	Element temp_el; // Intialize a element object to store the string key and string value we pass in
	temp_el.key_ = key;// stores the key in our temp_el object :)
	temp_el.value_= value;// stores the val in temp_el object :)
	temp_el.index_=vec_.size();
	auto element_itr = vec_.begin();
	while(element_itr!=vec_.end()){//Use itr based loop and see if the key is in the vector to begin with
		
		if((*element_itr).key_ == key){
			return false;// If the key is already in the vector we want to return false 
		
		}
	++element_itr;// increameant the itr by 1 each time to step through each element.	
	}
	
	vec_.push_back(temp_el);//If we've reached this point the key must not be in the vector. So we will push our temp_el onto vec_
	sz_++;// Increase the size to accomandate the new element we just inserted 
	sort(vec_.begin(), vec_.end(),[](const Element &e1, const Element &e2)// Lamda to make a compairson of two elements 
	{return e1.key_ < e2.key_;});					      //and their key since they are sorted by the key values 

	return true;	
}

// Things to note*
// we need to handle the edge cases. What happens if pos_itr is at the beginining? What if its at the end?! What do we do???
// Keep in mind our end game is to return pos_itr -1. Why? We know that upper_bounds returns an pointer to the value greater than the 
// one your comparing against. 

Element* TriMap::find_key(const string& key){

	auto pos_itr = upper_bound(vec_.begin(), vec_.end(), key, [](const string &k, const Element &e1)
	
	{return k < e1.key_;});

	
	if(pos_itr == vec_.begin()){//Edge case #1 where there is vector is empty. You cant go one minus the start of an empty vector 
		return nullptr;	   // and return a pointer. So we set the pos_itr = to the beginining("vec_.begin()") to handle that.
	}
	
	
	else if(key == (*(pos_itr-1)).key_){ //We find they key we are searching for and we return its position -1 to account for the way
		return &(*(pos_itr-1));	    // upper_bound searches through the container.

	}

	
	else{// Edge case #2, something weird happnened, we didnt find the key  and the pos_itr is not at the beginining
		return nullptr;
	}
}



Element* TriMap:: find_value(const string& value){
	Element new_el; // Intialize a element object and feed it the string value we pass in
	new_el.value_ = value; 
	auto element_itr = vec_.begin();			
	while(element_itr!= vec_.end()){  // Do a linear itr search through all the elements in vec. If we find element.val = to the one
		if((*element_itr).value_ == new_el.value_){// we want we return the adress of the deref pointer
			return &(*(element_itr));		
	
		}
	 ++element_itr;
	}

	return nullptr;	// If we got here we didnt find the value :(

}

Element* TriMap:: find_index(size_t index){
	Element new_el;// Intialize a element object and feed it the string index we pass in
	new_el.index_ = index; 

	for(auto element_itr = vec_.begin();element_itr!=vec_.end(); ++element_itr){//Do a linear search through all the elements again
										    // in vec. If we find an element.val = to the one
		if((*element_itr).index_ == new_el.index_)			    // we want we return the adress of the deref pointer
			return &(*(element_itr));				    // that points to that value.
	}


	return nullptr;// If we got here we didnt find the value :(



}

bool TriMap::remove(string key){
	

	auto element_pointer = std::find_if(vec_.begin(), vec_.end(),// Use find_if algorithm to return a pointer to the element 
		[&key](const Element &e1){		             // that has the key we are looking for to identify it for removal
		  return e1.key_ == key;			     // small lamda to compare the key we take in and the key thats 
		}						     // in the vec_
		);


	 if(element_pointer == vec_.end()){// If we are stopped here then then the key was not in vec_  and find_if has returned 
		return false;		   //  the last element in the container(vec.end())
	 }

	 auto index_value = (*element_pointer).index_; //We need the index value of the element before we erase it to comapre it
	vec_.erase(element_pointer);//against the index value of the remaining elements! 
	sz_ --;
	for(auto &removed_elm_vec: vec_){ // Loop through the remaining elements 

		if((removed_elm_vec).index_ > index_value){// If their index value is > than than the index value of the element we just
			(removed_elm_vec).index_-=1;// removed than their index value should be decreased by one. 
			
		}
	}
		
	return true; 
}