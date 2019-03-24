#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
using std::cout; using std::cin; using std::endl; using namespace std;

int main ()
{
float real_number_alpha=0;
float imaginary_number_alpha=0;

float real_number_beta=0;
float imaginary_number_beta=0;

cin >>real_number_alpha>>imaginary_number_alpha>>real_number_beta>>imaginary_number_beta;


float complex_result_add       = imaginary_number_alpha + imaginary_number_beta;
float real_result_add          =  real_number_alpha     +  real_number_beta;

float complex_result_sub       = imaginary_number_alpha - imaginary_number_beta;
float real_result_sub          =  real_number_alpha     - real_number_beta;

float complex_result_multi     =  ((imaginary_number_alpha*real_number_beta)+(real_number_alpha*imaginary_number_beta));

float real_result_multi        =  ((real_number_alpha * real_number_beta)-(imaginary_number_alpha* imaginary_number_beta));

float complex_result_div       = ((imaginary_number_alpha*real_number_beta)-(real_number_alpha*imaginary_number_beta))/ ((pow(real_number_beta,2)+pow(imaginary_number_beta,2)));

float real_result_div          = (((real_number_alpha)*(real_number_beta))+((imaginary_number_alpha)*(imaginary_number_beta)))/(pow(real_number_beta,2)+pow(imaginary_number_beta,2));


stringstream complex_stream_add;
complex_stream_add << fixed << setprecision(2) << complex_result_add <<"i";
string complex_str_add = complex_stream_add.str();

stringstream real_stream_add;
real_stream_add << fixed << setprecision(2) << real_result_add;
string real_str_add = real_stream_add.str();

stringstream complex_stream_sub;
complex_stream_sub << fixed << setprecision(2) << complex_result_sub <<"i";
string complex_str_sub = complex_stream_sub.str();

stringstream real_stream_sub;
real_stream_sub << fixed << setprecision(2) << real_result_sub;
string real_str_sub = real_stream_sub.str();

stringstream complex_stream_multi;
complex_stream_multi << fixed << setprecision(2) << complex_result_multi <<"i";
string complex_str_multi = complex_stream_multi.str();

stringstream real_stream_multi;
real_stream_multi << fixed << setprecision(2) << real_result_multi;
string real_str_multi = real_stream_multi.str();

stringstream complex_stream_div;
complex_stream_div << fixed << setprecision(2) << complex_result_div <<"i";
string complex_str_div = complex_stream_div.str();

stringstream real_stream_div;
real_stream_div << fixed << setprecision(2) << real_result_div;
string real_str_div = real_stream_div.str();

cout<< real_str_add << " " << "+" <<" "<< complex_str_add <<endl;
cout<< real_str_sub << " " << "+" <<" "<< complex_str_sub <<endl;
cout<< real_str_multi << " " << "+" <<" "<< complex_str_multi <<endl;
cout<< real_str_div << " " << "+" <<" "<< complex_str_div <<endl;

return 0;

}