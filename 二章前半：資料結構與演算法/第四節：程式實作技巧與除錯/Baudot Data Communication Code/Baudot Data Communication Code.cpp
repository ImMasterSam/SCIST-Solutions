#include<iostream>
#include<cmath>
using namespace std;

int dec(string s){
	
	int l = 5;
	int sum = 0;
	
	for(int i=0;i<l;i++){
		
		sum += (s[i]-'0')*pow(2, l-i-1);
		
	}
	
	return sum;
	
}

int main(){
	
	string table[2];
	
	getline(cin, table[0]);
	getline(cin, table[1]);
	
	string code;
	
	while(getline(cin, code)){
		
		int shift = 0;
		
		int l = code.size()/5;
		
		for(int i=0;i<l;i++){
			
			int n = dec(code.substr(i*5, 5));
			
			if(n == 27)
				shift = 0;
			else if(n == 31)
				shift = 1;
			else
				cout << table[shift][n];
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}