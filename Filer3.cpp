//sircoderscupkiweightage
#include <iostream>
#include <fstream>
using namespace std;

string convert_int_to_string(int x){
	if(x<10)
    	return string(1, x + '0');
  return convert_int_to_string(x/10) + convert_int_to_string(x%10);
}

char checkSecond(string s){
	return s[1];
}

char plusone(const char c){
	char ans = c;
	if(isalnum(++ans))
		return ans;
	else{
		if(c=='9')
			return 'a';
		else
			return '.';
	}
}

int main(){

	string meow, pd = "PasswordData";
	
	ofstream fout;
	ifstream fin;
	
    char rn;
    int curr;
	for(int count=0; count<36; count++){
		rn = '0';
		curr = -1;
	 	meow = pd + convert_int_to_string(count) + ".txt";
	    fin.open(meow.c_str());
	    cout << meow << " opened for fin\n";
	    
	    string line;
	    
	    
	    meow = pd + convert_int_to_string(count) + "_" + convert_int_to_string(++curr) + ".txt";
		fout.open(meow.c_str());
		cout << meow << " opened for fout\n";

	    while (!fin.eof()) {
	    	
	        getline(fin, line);
	        
	        if(line=="sircoderscupkiweightage")
	        	break;
	        	
	        if( line=="" || (rn!=checkSecond(line) and plusone(rn)!=checkSecond(line)))
	        	continue;
	        	
			if(plusone(rn) == checkSecond(line)){
				rn = plusone(rn);
				fout.close();
				meow = pd + convert_int_to_string(count) + "_" + convert_int_to_string(++curr) + ".txt";
    			fout.open(meow.c_str());
				cout << meow << " opened for fout\n";
			}
			
		    fout << line << endl;
	    }
	    
	    fin.close();
	}
	fout.close();
	
	return 0;
}
