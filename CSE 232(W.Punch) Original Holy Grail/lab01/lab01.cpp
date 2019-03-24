#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    long user_int;
    double KM_distance=0;
    double Miles_distance=0;
    double trip_time = 0;
    long secs=0;
    
    
    cout << fixed << setprecision(2);
    //cout << "Enter an int to represent the number of days after 9/1/17: "<<endl;

    cin >> user_int;
    
    secs = 60.00*60.00*24.00*user_int;
    KM_distance = 39.33 * 149598000.00 + secs * 14.24;
    Miles_distance = 39.33 * 92955800.00 + secs * 8.85;
    trip_time = (KM_distance * 1000.00 / 299792458.00) / (60.00*60.00) * 2.00;
    
    cout <<KM_distance << endl; 
    cout <<Miles_distance << endl;
    cout <<trip_time << endl;
    
    
        
    return 0;
}
