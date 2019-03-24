#ifndef PAL_H
#define PAL_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<utility>
using std::swap;
#include<sstream>
using std::ostringstream;
#include<string>
using std::string;
#include<utility>
using std::pair;

// forward declaration so we can make Element a friend of PAL
template<typename T>
class PAL;

//node class
template <typename T>
class Element{
private:
  Element *next_ = nullptr;
  string name_ = "";
  T color_ = T();
  
public:
  Element()=default;
  Element(string name, T d) : next_(nullptr), name_(name), color_(d){};
  friend ostream& operator<<(ostream& out, Element& n){

    // PUT YOUR CODE HERE
    
  }
  friend class PAL<T>;
};


template<typename T>
class PAL{
private:
  Element<T> *back_ = nullptr;
  Element<T> *front_ = nullptr;
  void print_list(ostream& out);  
public:
  PAL()=default;
  PAL(Element<T> n) : back_(&n), front_(&n) {};
  PAL(string n, T d);
  PAL(const PAL&);
  PAL& operator=(PAL);
  ~PAL();
  void add(Element<T> &n);
  void add(string name, T dat);
  pair<Element<T>*, Element<T>*> find(string name);    
  pair<Element<T>*, Element<T>*> find(Element<T> &n);
  void move_forward1(Element<T> &n);
  void move_to_front(Element<T> &n);  
  void move_back1(Element<T> &n);
  void move_to_back(Element<T> &n);  

  friend ostream& operator<<(ostream& out, PAL<T>& sl){
    sl.print_list(out);
    return out;
  };
};

// START REST OF THE CODE HERE
