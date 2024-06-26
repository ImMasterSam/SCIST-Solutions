#include<iostream>
using namespace std;

string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){

	int tbl[128];
	
	for(int i=1;i<(int)key.size();i++){
		
		tbl[key[i]] = key[i-1];
		
	}
	
	tbl[' '] = ' ';
	
	string s;
	
	while(getline(cin, s)){
		
		for(int i=0;i<(int)s.size();i++){
			
			s[i] = tbl[s[i]];
			
		}
		
		cout << s << "\n";
		
	}
	
	return 0;
}