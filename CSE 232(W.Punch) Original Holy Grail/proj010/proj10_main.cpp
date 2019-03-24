#include<iostream>
using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<string>
using std::string; using std::to_string;
#include<iomanip>
using std::boolalpha;
#include<cassert>
#include "proj10_package.h"
#include "proj10_knapsack.h"

int main(){

  cout << boolalpha;

//  Package p(2,3);
//  Package p2(1,1);
//  Knapsack ks1(20);

//  auto cap = ks1.capacity();
//  auto sz = ks1.size();
//  auto weight_lim = ks1.weight_limit();

//long l;
//bool b;
//ostringstream oss;
//string s, ans;
//Knapsack ks(30,2);
//ks.add({10,10});
//ks.add({10,10});
//cout<<"Ks cap"<<" "<< ks.capacity()<<endl;
//cout<<"Ks size"<<" "<< ks.size()<<endl;
//Knapsack copy_ks(ks);
//l= copy_ks.capacity();
//cout<<"copy cap"<<" "<< l<<endl;
//l= copy_ks.size();
//cout<<"copy size"<<" "<< l<<endl;
//b=copy_ks.add({1,1});
//cout<< "Can we add the package (2,1)"<<" "<<b<<endl;
//ks.add({2,2});
//cout<<"Ks cap"<<" "<< ks.capacity()<<endl;
//oss << ks;
//s = oss.str();
//ans = "10:10, 10:10, 2:2";
//l = ks.weight();
//cout<< " Original Weight"<<" "<<l<<endl;
//l = copy_ks.weight();;
//cout<<"Copy weight"<<" "<<l<<endl;
//oss.str("");
//oss << copy_ks;
//s = oss.str();


//long l;
//Knapsack ks(51,3);
//solve_KS("packages.txt", ks);
//l = ks.weight();
//cout<<"Weight"<<" "<<l<<endl;
//l = ks.priority();
//try{
//  solve_KS("badfilename", ks);
////  ASSERT_FALSE(true);
//}
//catch (runtime_error& e){
////  ASSERT_TRUE(true);
//}





//  auto cap_two = ks2.capacity();
//  auto sz_two = ks2.size();
//  auto weight_lim_two = ks2.weight_limit();
////  assert(p.weight_ == 1);
////  assert(p.priority_ == 1);
//  cout<<"Is p1's priority/weight ration > p2's?"<<" "<< package_compare(p,p2)<<endl;
//  cout<<"looking at param cstr #1"<<" "<< "Cap"<<cap<<" "<<"Size"<<sz<<" "<<"weight"<<weight_lim<<endl;
//   cout<<"Looking at param cstr #2"<<" "<< "Cap"<<cap_two<<" "<<"Size"<<sz_two<<" "<<"weight"<<weight_lim_two<<endl;

//long l1,l2,l3,l4,l5;
//bool b1,b2,b3,b4;
//Knapsack ks(25,3);
//b1 = ks.add({10,10});
//cout<<"can we add the package?"<<" "<<b1<<endl;
//b2 = ks.add({10,111});
//l1 = ks.capacity();
//cout<<"cap"<<" "<<l1<<endl;
//b3 = ks.add({10,115});
//cout<<"can we still add the package?"<<" "<<b3<<endl;
//ks.add({10,10});
//l2 = ks.capacity();
//cout<<"cap"<<" "<<l2<<endl;
//l3 = ks.weight();
//l4 = ks.priority();
//l5 = ks.size();
//cout<<"size"<<" "<<l5<<endl;
//cout<<"weight"<<" "<<l3<<endl;
//cout<<"priority"<<" "<<l4<<endl;
//cout << ks.empty() <<endl;
//  cout << ks.add(Package(10,10)) << endl;
//  cout << ks.add(Package(10,10)) << endl;  
//  cout << ks.add(Package(1,10)) << endl;
// cout <<  ks.add(Package(1,10)) << endl;
//  cout << "Size:" << ks.size() << endl;
//  cout << "Weight:" << ks.weight() << endl;
//  cout << "Capacity:" << ks.capacity() << endl;
//  cout << "Priority:" << ks.priority() << endl;
//  cout << ks << endl;
//  cout << ks.add(Package(2,10)) << endl;  
//  cout << "Size:" << ks.size() << endl;
//  cout << "Weight:" << ks.weight() << endl;
//  cout << "Capacity:" << ks.capacity() << endl;
//  cout << "Priority:" << ks.priority() << endl;
//  
//  cout << ks << endl;

  Knapsack ks2(15, 3);
  solve_KS("packages.txt", ks2);
  cout << ks2 << endl;
  cout << "Weight:"<<ks2.weight() << endl;
  cout << "Priority:"<<ks2.priority() << endl;
}
		 
