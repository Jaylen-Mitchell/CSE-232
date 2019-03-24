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
#include "proj11_trimap.h"
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::vector; 
using std::getline; using std:: map; using std::ifstream; using std::stod; using std:: pair; using std:: make_pair; using std:: ostringstream; using std:: ostream; 





int main(){

////TriMap<string,string> m1("key","value");
////ostringstream oss;
////oss << m1;
////string s1 = oss.str();
////cout<< s1<<endl;


////TriMap<string, string> m2;
////m2.insert("w","x");
////cout << m2 << endl;
////m2.insert("c", "d");
////cout << m2 << endl;
////m2.insert("a","b");
////cout << m2 << endl;
////m2.insert("y", "z");
////cout << m2 << endl;
////Element<string, string>* result = m2.find_key("y");

////ostringstream oss2;
////oss2 << *result;
////string s2 = oss.str();
////cout<< s2<<endl;


////bool insert1;

////TriMap<string,string> m3;
////m3.insert("harry","fellow");
////insert1 = m3.insert("big","bear");
////ostringstream oss3;
////oss3 << m3;
////string s3 = oss3.str();
////cout<<s3<<endl;


////TriMap <long, long>m4;
////m4.insert(2,20);
////m4.insert(1, 10);
////m4.insert(4,40);
////m4.insert(3,30);
////bool result_ans = m4.remove(3);
////size_t sz = m4.size();
////ostringstream oss4;
////oss4 << m4;
////string s4 = oss4.str();
////cout<<s4<<endl;
////cout<<"Size is now"<<" "<<sz<<endl;

//TriMap<long,long> m1;
//m1.insert(2,20);
//m1.insert(1,10);
//m1.insert(4,40);
//m1.insert(3,30);
//m1.insert (6,60);
//auto sz = m1.size();
//cout<<"Size"<<sz<<endl;
//cout<<"M1"<<m1<<endl;
//m1.remove(3);
//cout<<"M1 after remove"<<" "<<m1<<endl;
////cout<<"M1"<<" "<<m1<<endl;
//TriMap<long, long> m2(m1);
////cout<<"M1 Copy"<<" "<<m2<<endl;
//m2.insert(5,50);
////cout<<m2<<endl;
//m2.remove(4);

//ostringstream oss1;
//oss1 << m1;
//string s1 = oss1.str();
//cout<<s1<<endl;
//string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";

//ostringstream oss2;
//oss2 << m2;
//string s2 = oss2.str();
//string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";
//cout<<s2<<endl;



TriMap<long,long> m1;
m1.insert(2,20);
m1.insert(1,10);
m1.insert(4,40);
m1.insert(3,30);

TriMap<long, long> m2;
m2 = m1;
cout<<m2.size()<<endl;
m2.insert(5,50);
m2.remove(4);

ostringstream oss1;
oss1 << m1;
string s1 = oss1.str();
cout<<s1<<endl;
string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";


ostringstream oss2;
oss2 << m2;
string s2 = oss2.str();
cout<<s2<<endl;
string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";






return 2;
}
