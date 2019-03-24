#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;

// private Element, friend of TriMap class
template <typename K, typename V>
class Element{

private:
  K key_;
  size_t index_ = 0;
  Element *next_ = nullptr;  

public:
  V value_;
  
  Element() = default;
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

  // *defined* in the class, makes templating easier.
  friend ostream& operator<<(ostream& out, Element& e){
    out << e.key_ << ":" << e.value_ << ":" << e.index_;
    return out;
  }
  friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{

private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 0;
  
  // a private function, used by operator<<
  void print_list(ostream& out);
  
public:
  TriMap() = default;
  TriMap(K,V);
  TriMap(const TriMap&);
  TriMap& operator=(TriMap);
  ~TriMap();
  long size();
  bool insert(K,V);
  bool remove(K);
  Element<K,V>* find_key(K);
  Element<K,V>* find_value(V);
  Element<K,V>* find_index(size_t);  
  
  // *defined* in the class, makes templating easier.
  // uses private method print_list
  // you can remove print_list and just do it here if you
  // prefer. I won't test print_list
  friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
    sl.print_list(out);
    return out;
  };
};

template<typename K, typename V>
TriMap<K,V>::TriMap(K key, V value){
    auto index = size_;
    Element<K,V>* new_Element_node = new Element<K,V>(key, value, index);// This node doesnt exist  before hand so we have to allocate memory to construct it
    head_ = new_Element_node;
    tail_ = new_Element_node;
};

/* 
bit of work. we need to remember a pointer that walks
down the list to copy, as tail_ walks down the new list. 
Make a new node (copy the current node of the list we are copying), 
update the tail_->next_ to point to the new node, update tail_ to new node
 */
template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& tm){
  if (tm.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;

  }

}

template<typename K, typename V>
TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
    // x = y
    // x.operator=(y);
    swap(head_, tm.head_);
    swap(tail_, tm.tail_);
    return *this;


}
	

// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
template<typename K, typename V>
TriMap<K,V>::~TriMap(){

}

template<typename K, typename V>
long TriMap<K,V>::size(){
  return size_;
}

template<typename K, typename V>
bool TriMap<K,V>::insert(K key, V value){
  // very important, what are all the cases here!!!!
  // elements are inserted in *key order*
	auto index = size_;
	Element<K,V>*new_Node = new Element<K,V>(key,value, index);

	 if (find_key(key)){
		return false;
	 }//Edge case #2
	 if (head_ == nullptr){// If there arent any nodes currently present before we insert the first node then after we insert it head and tail should point to the same place
        	tail_ = new_Node;
        	head_ = new_Node;
		size_++;
		return true;
        	
   	 }
//	 Element<K,V> *current_node,*previous_node;
//	Edge case #2
   	 else if(head_->key_ > key){// If we get here then the heads data key is greater than they key we tried to insert and we need to update heads key to key we want to insert
			new_Node->next_ = head_;//Ex, heads key value is 3 and we want to insert key value of 1. If we want to insert the key value 1 we need to reset heads_ key value
			head_ = new_Node;
			size_++;
			return true;
	}

	else{//Edge Case #3
		// Similair situation to previous edge case 
		for(auto ptr_walker = head_; ptr_walker!= nullptr; ptr_walker= ptr_walker->next_){
			new_Node->next_ = ptr_walker;//Shadow that is one behind 
			if(ptr_walker->next_->key_ > key){// Compares the next ptr_walker key value instead of the current one
			 	new_Node =ptr_walker-> next_;
			  	ptr_walker->next_ = new_Node;
				size_++;
				return true;

			}
		}
	}
	tail_->next_ = new_Node;// If we made it here than the keys value is greater than any nodes key value  in the linked list. As such it goes to the end of the list aka tail
	tail_ = new_Node ;
	size_++;
	return true;
}
    
template<typename K, typename V>
bool TriMap<K,V>::remove(K key){
  // again, what are all the cases!!!
  // also, if you delete a node, the indicies of all
  // nodes with a higher index have that index reduced by one

  
}
 

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K key){
   //no binary search, just linear search
 	Element<K,V> *result = nullptr;
  	for(Element<K,V> *current_node_ptr = head_; current_node_ptr!= nullptr; current_node_ptr= current_node_ptr->next_){
		if(current_node_ptr->key_ == key){
			result = current_node_ptr;
			break;
		}

	}
	return result;
}    

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V val){
  // linear search

	Element<K,V> *result = nullptr;
  	for(Element<K,V> *current_node_ptr = head_; current_node_ptr!= nullptr; current_node_ptr= current_node_ptr->next_){
		if(current_node_ptr->value_== val){
			result = current_node_ptr;
			break;
		}

	}
	return result; 
}    



template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t i){
  // linear search
	Element<K,V> *result = nullptr;
  	for(Element<K,V> *current_node_ptr = head_; current_node_ptr!= nullptr; current_node_ptr= current_node_ptr->next_){
		if(current_node_ptr->index_== i){
			result = current_node_ptr;
			break;
		}

	}
	return result; 
}    




//template<typename K, typename V>
//void sort(){


//    if (head!= 0)
//    {
//        Element<K,V>* current = head;
//        Element<K,V>* prev = 0;
//        Element<K,V>* tempNode = 0;
//        bool changeFlag = false;
//        for (int i = 0; i < size_; i++)
//        {
//            while (current->next!= 0)
//            {
//                tempNode = current->next;

//                if (current->key > tempNode->key)
//                {
//                    changeFlag = true;
//                    current->next = tempNode->next;
//                    tempNode->next = current;
//                    if (prev != 0)
//                        prev->next = tempNode;
//                    prev = tempNode;
//                    if (head_ == current)
//                        head_ = tempNode;
//                    if (current->next == 0)
//                        end = current;
//                }
//                else
//                {
//                    prev = current;
//                    current = current->next;
//                }
//            }
//            if (changeFlag == false)
//                break;
//            else
//            {
//                prev = 0;
//                current = head_;
//                changeFlag = false;
//            }
//        }
//    }
//}

template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &out){
    ostringstream oss;
    Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
	oss << *ptr << ", ";
    string s = oss.str();
    out << s.substr(0,s.size()-2);

};


#endif
  
