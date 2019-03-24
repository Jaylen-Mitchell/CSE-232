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



string lower_and_strip(string s){


string lower_string_strip = s; 

   
   for (size_t i = 0; i < lower_string_strip.length(); i++) {
        if (!isalpha(lower_string_strip[i])){
        lower_string_strip.erase(i,1);
  
         }
        }
     
transform(lower_string_strip.begin(), lower_string_strip.end(), lower_string_strip.begin(), ::tolower);
lower_string_strip.erase (std::remove_if(lower_string_strip.begin (), lower_string_strip.end (), ispunct), lower_string_strip.end ());


return lower_string_strip;
}



int   return_encoded_char(string key, string::size_type &start, char C){
       int start_temp; 
       bool flag=false; 
       //string lower_str_strip_key = lower_and_strip(key);
       int distance=0;
       //string decoded_str = "";
       //int distance_start = 0; 
       for (size_t i=start; i<=key.length(); i++){ // "Start" is an index. You want to check from that index until the end of string key
            //cout<<i<<endl;                                        // If while checking that index I find the ch im looking for distnace will be from that
            if (key[i] ==  C)                       // current "i" index - the "start" index 
            {                                                       // start will then update to "i" index. Flag will return true!
                //distance_start+= lower_str_strip_key[i];
                distance=(i-start);
                start=i;
                flag= true; 
             return distance;
           
            }
            
 


        }
       if (flag == false){// This says hey if didnt find the ch in the current index range I'm looking at then it must be elsewhere. We will need to start
                          //looking at the start of the string by making "i"=0. We will go all the way to the most recent start index.  
            for(size_t i=0; i<start; i++){ 
                   
                   if (key[i]==  C)// If we find the the ch here we will need to take the start index value we began with, add the 
                   {start_temp=start;              // remaining index's of the string to wrap around the beggining. We will then do like before. Where the
                   start=i;                        // distance will be the length of the key - the previous start + the "i" index  we found the ch at!
                    return ((key.size())-(start_temp)+i);}
                        }
                   }
       
start=0;
return key.size()+1;
    }   
    
    
    
    
string encode(string message, string key){

size_t start=0;
string lower_strip_and_strip_message = lower_and_strip(message);
string encoded_message ="";

for( size_t i=0; i< lower_strip_and_strip_message.length(); i++){
    
    int temp =  return_encoded_char(key,start, lower_strip_and_strip_message[i]);
    encoded_message+= to_string(temp)+" ";
    //cout<< return_encoded_char<<endl;
   


    }
return encoded_message;
}



char return_decoded_char(string key, string::size_type &start, int num){
       
       //string lower_str_strip_key = lower_and_strip(key);
       char ch=' ';
       int n = 0;
       for (size_t i=start; i<=key.length(); i++){ // "Start" is an index. You want to check from that index until the end of string key
            //cout<<i<<endl;                                        // If while checking that index I find the ch im looking for distnace will be from that
            if ((num + start) == i)                                   // current "i" index - the "start" index 
            {                                                       // start will then update to "i" index. Flag will return true!
                ch = key[i];
                //cout<<ch<<endl;
                start=i;
             return ch;
            }
            n += 1;
        }
 
        int remaining = (num - n+1)%key.length();

return key[remaining];
    }    





string decode (string encoded_text, string key){

size_t start=0;
int num=0;
//string lower_strip_message = lower_and_strip(encoded_text);
string  decoded_message ="", num_str="";
//cout << "Key: " << key << endl;
for( size_t i=0; i<encoded_text.size(); i++){
    if(encoded_text[i] != ' '){
    num_str+=(encoded_text[i]);
    //cout<<num_str<<endl;
    }
    if(((encoded_text[i]== ' ') && (i !=0)) || (i == encoded_text.size()-1)){
        num = stoi(num_str);
        //cout<<num<<endl;
        char character = return_decoded_char(key,start,num);
        decoded_message+= character;
        //cout << "Last: " << character << endl;
        start = key.find(character);
        //cout << "New start: " << start << endl;
        num_str= "";
       }
    }
    return decoded_message;
}






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
  }  

    
  } // of switch

} // of main
  
  
