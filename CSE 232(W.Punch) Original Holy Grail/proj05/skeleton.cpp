#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::stoi; using std::to_string;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<iterator>
using std::distance; using std::back_inserter;
#include<algorithm>
using std::transform;
#include<cctype>
// whatever headers you need

// your functions here


int main (){
  cout << boolalpha;

  int test_case;
  cin >> test_case;

  switch (test_case){

  case 1 : {
    string line;
    cin.ignore(20, '\n');
    getline(cin, line);
    cout << lower_and_strip(line) << endl;
    break;
  } // of case 1

  case 2 : {
    string key;
    char C;
    int num;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> C;
    cin >> start;
    num = return_encoded_char (key, start, C); 
    cout << num << " " << start << endl;
    break;
  } // of case 2

  case 3 : {
    string key, line;
    string::size_type start=0;
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << encode(line, key) << endl;
    break;
  } // of case 3   

  case 4 : {
    int num;    
    string key;
    char C;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> num;
    cin >> start;
    C = return_decoded_char (key, start, num);
    cout << C << " "<<start << endl;
    break;
  } // of case 4

  case 5 : {
    string key, line;
    string::size_type start=0;    
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << decode(line, key) << endl;
    break;
  } // of case 5
    
  } // of switch

} // of main
  
  
