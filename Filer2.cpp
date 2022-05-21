//sircoderscupkiweightage
#include <iostream>
#include <fstream>
using namespace std;

string convert_int_to_string(int x){
	if(x<10)
    	return string(1, x + '0');
  return convert_int_to_string(x/10) + convert_int_to_string(x%10);
}

char checkFirst(string s){
	return s[0];
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

	string sanit = "Sanitized_";
	string pd = "PasswordData";
	
	int curr = 0;
	
	ofstream fout;
	string meow = pd + convert_int_to_string(curr) + ".txt";
    fout.open(meow.c_str());
	cout << meow << " opened for fout\n";
	
    char rn = '0';
    
	for(int count=1; count<28; count++){
		
	    ifstream fin;
	 	meow = sanit + convert_int_to_string(count) + ".txt";
	    fin.open(meow.c_str());
	    cout << meow << " opened for fin\n";
	    
	    string line, purani="yo";

	    int track = 0;
	    while (!fin.eof()) {
	    	
	        getline(fin, line);
	        
	        if(line=="sircoderscupkiweightage")
	        	break;
			
	        if(purani==line)
	        	continue;
	        	
	        if(line.length()<3 || line.length()>12 || line=="" || (rn!=checkFirst(line) and plusone(rn)!=checkFirst(line)))
	        	continue;
	        	
			if(plusone(rn) == checkFirst(line)){
				cout << "\n\nold rn is " << rn << " and line is " << line << " and plusone(rn) == checkFirst(line) -> " << plusone(rn) << " == " << checkFirst(line) <<"\n\n";
				rn = plusone(rn);
				fout << "sircoderscupkiweightage" << endl;
				fout.close();
				string meow = pd + convert_int_to_string(++curr) + ".txt";
    			fout.open(meow.c_str());
				cout << meow << " opened for fout\n";
			}
			
			if(++track==4){
		        fout << line << endl;
		        track=0;
			}
			
	    }
	    
	    fin.close();
	}
	fout.close();
	
	return 0;
}
