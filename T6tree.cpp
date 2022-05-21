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

		void Insert(string value)
		{
			Insert(value, root, 1);
		}

		void Insert(string value, Node* ptr, int curr)
		{
			char ch = value[curr];

			if(intify(ch) == -999) {
				return;
			}

			if(!ptr->children[intify(ch)]) {	//agar head exist nahi karta tou head par set kare.
				ptr->children[intify(ch)] = new Node(value);
				ptr->children[intify(ch)]->data = value;
			//	cout << "-";
				return;
			}

			else 
				Insert(value, ptr->children[intify(ch)], ++curr);
		}

		Node* search(string str)
		{
			return search(root, str, 1);
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
			cout << "\nTree cleared\n";
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

	cout << "\t\t\tVeryFast Password Checker\n\n";

	T6AryTree* ref[SIZE];

	ifstream fin;
	string pd = "PasswordData";
	string str, st;
	
	for(int i = 0; i < SIZE; i++) {	//build 36 trees with alphabets as roots
		if(i < 10)
			ref[i] = new T6AryTree(num[i]);	//send numbers to create their respective trees
		else
			ref[i] = new T6AryTree(alpha[i - 10]); //send alphabets from other array to create root
	}

	
	do{
		cout << "\n\nEnter password (or -1 for exit): ";
		cin >> st;
		
		if(st=="-1")
			break;
		
		cout << "\t\t####  Please Wait A Moment ####\n\n";
				
		string meow = pd + convert_int_to_string(intify(st[0])) + ".txt";
	    fin.open(meow.c_str());
	    
	    while(!fin.eof()) {
			fin >> str;
		//	cout << str << " ";
			if(str.length()>=st.length())
				ref[intify(st[0])]->Insert(str);
		}
		cout << "done";
		fin.close();
		
		Node* temp = ref[intify(st[0])]->search(st);
		if(!temp)
			cout << "\nEntered Password is Unique\n";
		else{
			if(temp->data == st){
				cout << "\n" << temp->data << " found in database\n";
				cout << "\nTry : " << ref[intify(st[0])]->recommend(temp);
			}
			else
				cout << "\nEntered Password is Unique\n";
		}
			
		ref[intify(st[0])]->clearTree();
			
	} while(1);
	
	cout << "Thank You\n";
	return 0;
}
