
// beaufort cipher, http://practicalcryptography.com/ciphers/classical-era/beaufort/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream> // stringstream
#include <ios>
#include <algorithm>
using std::cout; using std::cin; using std::endl; using std::boolalpha; using std::stoi; using std::string; using std::stringstream;




const string alphabet = "abcdefghijklmnopqrstuvwxyz";




string rotate_left(int user_rotate_amount, string user_str){
// Step through each 'char' and create a initial substr grabbing 'chars'from staring index up to rotate_amount. Then create a second substr from roate amount to end of string to grab second batch of 'chars'

// Each rotation is moving a single char to the left



	int universal_rotate_amount       = user_rotate_amount % user_str.length();// to calculate higher roatation amounts we can use 											the given rotate num and do mod the length of the 											string.This will give us the equivalent number of 											roatations.
	string initial_left_rotated_str = "";					  										 
	string last_left_rotated_str    = "";					 
	string complete_string          = "";
	if(user_rotate_amount < 0){
   	return user_str;
	}

        initial_left_rotated_str = user_str.substr(0,universal_rotate_amount);  									        
	last_left_rotated_str    = user_str.substr(universal_rotate_amount);// The actual rotation is just the swapping of these two 										     substr's
	complete_string          = last_left_rotated_str+initial_left_rotated_str;

	return complete_string;


}

char beaufort_letter(char plain_letter, char key_letter){ // Plain_letter char is a 'cahr' in the original message
	char ch;
	int index=0;
	int roatation_amount=0;
	if(islower(plain_letter)&&(islower(key_letter)) && (isalpha(plain_letter) && (isalpha(key_letter)))){
	}
	else{
	//cout<< "Not lower case letter"<<endl;
	return plain_letter;
	}


        roatation_amount = plain_letter-'a'; // finds amount of left rotations needed. This is given in project description! 
	
	string key = rotate_left(roatation_amount, alphabet);// The key is the orginal alphabet roatated left by the roatation_amount

	index =key.find(key_letter);// We find the index by looking up the postion of they 'ch' key_letter in the roatated alphabet key
        ch    = (alphabet[index]);// We than use this index to find the 'ch' in the original/normal alphabet

		return ch;

}



 char vigenere_letter(char plain_letter, char key_letter){
	char ch;
	int index=0;
	int roatation_amount=0;
	if(islower(plain_letter)&&(islower(key_letter)) && (isalpha(plain_letter) && (isalpha(key_letter)))){
	}
	else{
	//cout<< "Not lower case letter"<<endl;
	return plain_letter;
	}


        roatation_amount = plain_letter-'a'; // finds amount of left rotations needed. This is given in project description! 
	
	string key = rotate_left(roatation_amount, alphabet);// The key is the orginal alphabet roatated left by the roatation_amount

	index = alphabet.find(key_letter); // We are using the original alphabet to find the index for they key_letter

	ch    = (key[index]);// We than use this index to find the 'ch' in the rotated alphabet.
	return ch;



}

string encode_beaufort(string plain_text, string key){
	//string purged_str  = "";
	string beaufort_str="";
	unsigned int count=0;

	size_t i = 0;
	size_t len = plain_text.length(); // We gotta iterate through plain text and eliminate bad chars first ;)
		while(i < len){
   			 if (!isalnum(plain_text[i]) || plain_text[i] == ' '){
        			plain_text.erase(i,1);
       				 len--;
    			}
			else{
        		i++;
		}
	
	
}
	
	for(unsigned int index = 0; index < plain_text.length(); ++index, ++count){
		//cout << endl << "--" << plain_text[index] << "--" << key[count] << "--" << endl; 
		if (count >= key.length()){
			count=0;
		}
	//	if ((alphabet.find(plain_text[index]) != string::npos)&&(alphabet.find(key[count])!string::npos=string::npos)){
		if ((alphabet.find(plain_text[index]) != string::npos) && (alphabet.find(key[count]) != string::npos)){
			//cout << plain_text[index] << endl;
			//cout << key[count] << endl;
			beaufort_str+= beaufort_letter(plain_text[index],key[count]);
		

		}

	}
	return beaufort_str;

}


string encode_vigenere(string plain_text, string key){
	
	string vigenere_str="";
	unsigned int count=0;

	remove_if(plain_text.begin(), plain_text.end(), isspace);
	
	size_t i = 0;
	size_t len = plain_text.length();
		while(i < len){ 	// We gotta iterate through plain text and eliminate bad chars first ;)
   			 if (!isalnum(plain_text[i]) || plain_text[i] == ' '){ 
        			plain_text.erase(i,1);
       				 len--;
    			}
			else{
        		i++;
		}
	
	
}

	for(unsigned int index = 0; index < plain_text.length(); ++index, ++count){
		//cout << endl << "--" << plain_text[index] << "--" << key[count] << "--" << endl; 
		if (count >= key.length()){
			count=0;
		}
		if ((alphabet.find(plain_text[index]) != string::npos) && (alphabet.find(key[count]) != string::npos)){
			
			vigenere_str+= vigenere_letter(plain_text[index],key[count]);// If we cant find the 'char' in the const alphabet
									             // Then we dont want it!
		}

	}
	return vigenere_str;

}




int main (){
int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
    
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main