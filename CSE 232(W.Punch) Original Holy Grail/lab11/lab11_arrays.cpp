#include "lab11_arrays.h"

#include<string>
using std::string; using std::getline; using std::stol;
#include<utility>
using std::pair;
#include<iostream>
using std::ostream;
#include<fstream>
using std::fstream;
#include<algorithm>
#include<iterator>
using std::ostream_iterator;

bool is_even(long l) {
	return !(l%2);
}

void print_array(long ary[], size_t sz, ostream& out) {
	std:: copy(ary, ary+sz, ostream_iterator<long>(out,","));
}

size_t fill_from_file(long* (& ary), string f_name) {
	fstream fin;
	fin.open(f_name);
	string line = "";
	getline(fin, line);
	size_t count = stol(line);
	long *array = new long[count];
	for(size_t i = 0; i < count; i++) {
		getline(fin, line);
		*(array+i) = stol(line);
	}
	fin.close();
	ary = array;
	return count;
}

size_t concatenate(long* (& ary1), size_t sz1, long ary2[], size_t sz2) {
	long *new_array = new long[sz1 + sz2];
	unsigned long array_size = sz1+ sz2;
	unsigned long item_count =0;
	for(auto elements = 0u; elements < sz1; elements ++){
		new_array[item_count] = ary1[elements];
		item_count ++;
	}	
	for(auto elements = 0u; elements < sz2; elements ++){
		new_array[item_count] = ary2[elements];
		item_count ++;
	}	
	ary1 = new_array;

	return array_size;
} 

pair<long*, size_t> copy_evens(long ary[], size_t sz) {
	unsigned element_count =0;
	unsigned long even_count =0;
	for(auto elements = 0u; elements < sz; elements ++){
		if(is_even(ary[elements]))
		even_count ++;
		
	}
	long *new_array = new long[even_count];	
	
	for(auto elements = 0u; elements < sz; elements ++){
		if(is_even(ary[elements])){
			new_array[element_count] = ary[elements];
			element_count ++;
		}
	}
	return {new_array, even_count};
}
