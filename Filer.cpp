#include <iostream>
#include<string>
#include <fstream>
using namespace std;

bool check(string s){
	char c = s[0];
	int curr = 0;
	bool ans = isalnum(c);
	while(c!='\0' && ans){
		ans = isalnum(c);
		c = s[++curr];
	}
	return ans;
}

void smallify(string *temp){
	string s = *temp;
	
	char c = s[0];
	int curr = 0;
	char ans = tolower(c);
	while(c!='\0' && ans){
		ans = tolower(c);
		s[curr++] = ans;
		c = s[curr];
	}
	*temp = s;
}

string convert_int_to_string(int x){
	if(x<10)
    	return string(1, x + '0');
  return convert_int_to_string(x/10) + convert_int_to_string(x%10);
}

int main(){
	string Sanitized = "Sanitized_";
	string realuniq = "realuniq"; 
	string final = "HalfData";
	
	for(int count=1; count<31; count++){
		ofstream fout;
 		
 		string temp = Sanitized + convert_int_to_string(count) + ".txt";
	    fout.open(temp.c_str());
	 
	    ifstream fin;
	 	
	 	temp = realuniq + convert_int_to_string(count) + ".lst";
	    fin.open(temp.c_str());
	    
	    string line;
	    while (!fin.eof()) {
	    	
	        getline(fin, line);
	        
	        if(check(line)){
	        	smallify(&line);
	        	fout << line << endl;
			}
	    }
	    
	    fout.close();
	    fin.close();
	}
	int curr = 0;
	
	for(int count=1; count<22; count++){
		ofstream fout;
		
		string meow = final + convert_int_to_string(count) + ".txt";
		cout << "\nOpened " << meow << " for fout\n";
	    fout.open(meow.c_str());
	 
	    ifstream fin;
	 
	 	meow = Sanitized + convert_int_to_string(count) + ".txt";
	    fin.open(meow.c_str());
	    cout << "\nOpened " << meow << " for fin\n";
	    
	    string line, temp = "";
	 	
	    while (!fin.eof()) {
	        getline(fin, line);
			   
	        if(line!=temp && line.length()<=12){
	        	if(++curr == 4){
	        		fout << line << endl;
					temp = line;
					curr = 0;
				}
			}
	    }
	    
	    fout.close();
	    fin.close();
	}
	
	return 0;
}
