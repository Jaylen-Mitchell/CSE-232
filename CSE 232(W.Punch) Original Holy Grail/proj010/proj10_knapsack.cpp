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
#include <stdio.h>
#include <string.h>
#include "proj10_package.h"
#include "proj10_knapsack.h"
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream;


	 ostream& operator<<(ostream &out_stream, Knapsack &ks){
		auto sz = ks.size_;
		for (long i = 0; i < ks.size_; i++ ){
 		 	auto package_object = ks.data_[i];
			if (sz >1){
				out_stream << package_object<<", ";// We set up a variable to reperesent the number of elemnts in the vector
			}				     // As we step through those elemnts if there is more than one we need a 	
			else if(sz<= 1){  // ", " between each element. We break this into different cases.
				out_stream << package_object;
			}
			sz--;// Start from max num of present elements and work our way down  							
		}							
		return out_stream;	
	}	

	
	// Knapsack is like a truck that will hold all of our packages. It has a fixed weight limit at its moment of construction
	Knapsack::Knapsack (size_t max){
		weight_limit_ = max;
		capacity_ =10;
		size_ =0;
		data_ = new Package[capacity_]{};//We dont know the capacity we will need (amount of packages ) at runtime so we have to dynamically allocate the memory. The data array 							 //will live in the heap!
//		cout<<"Initial Contents of data array"<<" "<<*(data_)<<endl;
	}

	Knapsack::Knapsack (size_t w_max, size_t cap){
		weight_limit_ = w_max;
		capacity_ = cap;
		size_ =0;
		data_ = new Package[capacity_]{};
//		cout<<"Initial Contents of data array"<<" "<<*(data_)<<endl;
	}
	// Getters 
	long  Knapsack:: capacity()       const  {return capacity_;}
	long  Knapsack:: size() 	  const  {return size_;}
	long  Knapsack:: weight_limit()   const  {return weight_limit_;}


	// Copy Constructor
	Knapsack:: Knapsack(const Knapsack& k){
   		 this-> size_ = k.size_;
		 this -> capacity_ = k.capacity_;
		 this-> weight_limit_ = k.weight_limit_;
   		 data_= new Package[capacity_];
    		 for (auto i = 0; i < size_; i++) {
       			 data_[i] = k.data_[i];
   		 }

	}

//	Knapsack& Knapsack::operator=(const Knapsack k){  

//        	std::swap( data_, k.data_);
//       	        std::swap( size_, k.size_ );
// 	        return *this;
//	}



	// Destructor
	Knapsack::~Knapsack(){  
    	 delete [] data_;
    	}

	bool Knapsack:: empty() const {
		
		if(size_== 0){// We know that if the size of the kanpsack is zero than it must be empty! Easy right?
			return true;
		}
		return false;//If the size wasn't zero its got stuff in it!
	}

	long Knapsack:: weight() const{
		long package_object_weight=0; 
		long empty_weight_sum=0;
		if(empty()== true){// If empty returns true than our if statement is true thus, the knapasack is empty and there isnt any weight 
			return empty_weight_sum;
		}
		
		for (long i = 0; i < size_; i++ ){
 		 	auto package_object = data_[i];
			package_object_weight += package_object.weight_;
		
		}
		return package_object_weight;
	}

	long Knapsack:: priority() const{
		long package_object_priority =0;
		long empty_priority=0;
		if(empty()== true){// If empty returns true than our if statement is true thus, the knapasack is empty and there isnt any priority
			return empty_priority;
		}
		
		for (long i = 0; i < size_; i++ ){// Loop through the array block using ptr arithmatic and sum the weights
 		 	auto package_object = data_[i];
			package_object_priority += (package_object.priority_);
		
		}
		return package_object_priority;


	}
	//Note to self, data_ is a package ptr that points to the first element in the capacity array block
	bool Knapsack:: add(const Package& pack){



		if(this->weight()+pack.weight_ > weight_limit_){
			return false;
			
		}
		else if( weight()+pack.weight_< weight_limit_ && size_ < capacity_){
			data_ [size_] =pack;// We assign a pkg ptr to point to a new pkg object using the size_ as an index marker for the cap array block.
			size_++;
//			cout<<"size growing to"<<" "<<size_<<endl;
//			auto pkg_obj = data_;
//			cout<<"I the Array now have the values"<<" "<<(*(pkg_obj+size_-1))<<endl;	
			this->weight();
			this-> priority();
//			cout<<"Weight currently is"<<" "<< this->weight()<<endl;
			return true;
		}
		else if( weight()+pack.weight_<= weight_limit_ && size_ <= capacity_){
			Package* new_data = new Package[capacity_*2]; // Create new array, twice the size
  			std::copy(data_, data_+size_ ,new_data);  // Copy old into new
			std::swap(data_, new_data);
 			delete [] new_data;  // delete old array
 			capacity_ = capacity_* 2;
			data_[size_]=pack;// add element in newly doubled array
			size_++;
			this-> priority();
			this-> weight();
			
			
			
		}
	
	return false;
	}


	void solve_KS(string fstring, Knapsack& k){
		vector<Package> vec_pkg;
		Package pack;
		long weight_value=0;
		long priority_value=0;
		std::ifstream infile(fstring);
		if(!infile.is_open()){
			throw std::runtime_error("badfilename");
		}
		if(infile.is_open()){
//			cout<<"Did we make it here?"<<endl;

			while(infile){// If we made it here the file was good and we will start extracting the data from the stream and store in the respective variables
				infile >> weight_value >> priority_value;
					vec_pkg.push_back(Package(weight_value, priority_value));
					
				}
			
			}
		std::sort(vec_pkg.begin(), vec_pkg.end(), package_compare);
		for(auto i = 0u; i< vec_pkg.size(); i++){//fill up the array using our vec_pkg container 
//			cout<<vec_pkg[i]<<endl;
			if(k.add(vec_pkg[i])==false)
				break;
			
		}
	



}


