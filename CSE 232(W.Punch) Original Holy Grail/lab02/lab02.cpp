#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
using std::cout; using std::cin; using std::endl; using namespace std;


int main (){

long user_long = 0;     //Intialize variables 

long persistance = 0;

long additive = 0;

long temp_var = 0;

cin >> user_long;// Get long from user

if (user_long <= 0){
    cout << "Error" << endl;// Check special cases 
}

if (user_long <= 9 and user_long > 0){
    cout << persistance << " " << user_long << endl;
}
if (user_long > 9){       // Set a loop to find single digit of input stream
    temp_var = user_long;
    while( temp_var > 0){
        additive += temp_var % 10;
        temp_var = temp_var / 10;
    }
    persistance = persistance + 1;
    while (additive > 9){
        additive = additive % 10 + (additive / 10) % 10;
        persistance = persistance + 1;
    }
    
    cout << persistance << " " << additive << endl;
}



return 0;    
}

