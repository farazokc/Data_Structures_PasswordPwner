#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>

using namespace std;
#define SIZE 36

int num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char alpha[26] = {  'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
                 };

class Node {
	public:
		string data;
		Node* children[SIZE];

		Node()				//construct tree node
		{
			data = "";
			for(int i = 0; i < SIZE; i++)
				children[i] = NULL;
		}

		Node(string val)
		{
			data = val;
			for(int i = 0; i < SIZE; i++)
				children[i] = NULL;
		}

		Node(char val)
		{
			data += val;
			for(int i = 0; i < SIZE; i++)
				children[i] = NULL;
		}
};

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

void grade(string st){
	int curr=0, score=0;
	char prev = '?', c = st[0];
	
	while(c!='\0'){
		if(c>='0' and c<='9')
			score+=12;
		else
			score+=8;
		if(c == plusone(prev) || c == prev)
			score-=5;
		prev = c;
		c = st[++curr];
	}
	
	if(score>=80)
		cout << "\nEntered Password is Strong\n";
	else if(score>= 50)
		cout << "\nEntered Password is Adequate\n";
	else
		cout << "\nEntered Password is Weak\n";
} 

string convert_int_to_string(int x){
	if(x<10)
    	return string(1, x + '0');
  return convert_int_to_string(x/10) + convert_int_to_string(x%10);
}


int intify(char ch)	//direct value return kar rha
{
	if(!isalnum(ch))
		return -999;
	if(ch >= '0' and ch <= '9')
		return ch - 48;
	else
		return ch - 87;

}

int random(){
	int num;
	
	srand(time(NULL));
	
	num = rand() % 10;
	
	return num;
}

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

class T6AryTree {
	Node* root;

	public:
		T6AryTree()		//default construct
		{
			root = NULL;
		}

		T6AryTree(char alphabet)	//assign root as alphabet
		{
			//only for initializing root nodes
			root = new Node(alphabet);
		}
		
		T6AryTree(char a1, char a2)	//assign root as alphabet
		{
			//only for initializing root nodes
			string st = "ab";
			st[0] = a1;
			st[1] = a2;
			////turn 2 chars into string st
			root = new Node(st);
		//	cout << "\nTree for " << st << " formed\n";
		}

		void Insert(string value)
		{
			Insert(value, root, 2);
		}

		void Insert(string value, Node* ptr, int curr)
		{
			char ch = value[curr];
			if(intify(ch) == -999) 
				return;
			

			if(!ptr->children[intify(ch)]) {	//agar head exist nahi karta tou head par set kare.
				ptr->children[intify(ch)] = new Node(value);
				ptr->children[intify(ch)]->data = value;
		//		cout << "-";
				return;
			}

			else 
				Insert(value, ptr->children[intify(ch)], ++curr);
			
		}

		Node* search(string str)
		{
			return search(root, str, 2);
		}

		Node* search(Node* ptr, string st, int curr)
		{
			if(!ptr)
			{
				return NULL;
			}
			
			char ch = st[curr];
			
			if(ptr->data == st or ch == '\0')
				return ptr;
			else		
				return search(ptr->children[intify(ch)], st, ++curr);
		}
		
		void clearTree(){
			clearNode(root);
//			cout << "\nTree cleared\n";
		}
		
		void clearNode(Node* ptr){
			if(ptr==NULL)
				return;
				
			for(int count=0; count<SIZE; count++){
				clearNode(ptr->children[count]);
				ptr->children[count] = NULL;
			}
				
			if(ptr!=root){
				delete ptr;
			}
		}
		
		string recommend(Node* ptr){
			int curr= random();
			string ans;
			do{
				ans = ptr->data;
				ptr = ptr->children[curr];
				curr = random();
			}while(ptr);
			ans+= convert_int_to_string(curr);
			return ans;
		}
};

int main()
{
	system("color f0");
	cout << "\t\t\tVeryFast Password Checker\n\n";

	T6AryTree* ref[SIZE][SIZE];

	ifstream fin;
	string pd = "PasswordData";;
	string str, st;
	
	for(int i = 0; i < SIZE; i++) {	//build 36 trees with two chars as roots
	char temp1;
	if(i<10)
		temp1 = num[i];
	else
		temp1 = alpha[i-10];

		for(int i2=0; i2<SIZE; i2++){
			char temp2;
			if(i2<10)
				temp2 = num[i2];
			else
				temp2 = alpha[i2-10];
			
			ref[i][i2] = new T6AryTree(temp1, temp2);	//send numbers to create their respective trees
		}
	}

	
	do{
		cout << "\nReminder: Don't use your actual password\n";
		cout << "\n\nEnter password (or -1 for exit): ";
		cin >> st;
		
		if(st=="-1")
			break;
			
		if(!check(st)){
			cout << "No special characters allowed\n";
			continue;
		}
		
		if(st.length()<3){
			cout << "Entered Password is Extremely Weak\n";
			continue;
		}
		
		cout << "\t\t####  Please Wait A Moment ####\n\n";
		
		smallify(&st);
		
		string meow = pd + convert_int_to_string(intify(st[0])) + "_" + convert_int_to_string(intify(st[1])) + ".txt";
	    fin.open(meow.c_str());
//		cout << meow.c_str() << " has been opened\n";
	    while(!fin.eof()) {
			fin >> str;
			
			if(str.length()>=st.length())
				ref[intify(st[0])][intify(st[1])]->Insert(str);
			
		}
//		cout << "Tree made\n";
		fin.close();
		
		Node* temp = ref[intify(st[0])][intify(st[1])]->search(st);
		if(!temp){
			cout << "\nEntered Password is Unique\n";
			grade(st);
		}
		else{
			if(temp->data == st){
				cout << "\n" << temp->data << " found in database\n";
				cout << "\nTry : " << ref[intify(st[0])][intify(st[1])]->recommend(temp);
			}
			else{
	//			cout << temp->data << endl;
				cout << "\nEntered Password is Unique\n";
				grade(st);	
			}
		}
			
		ref[intify(st[0])][intify(st[1])]->clearTree();
			
	} while(1);
	
	cout << "\n\n\t\tThank You";
	return 0;
}
