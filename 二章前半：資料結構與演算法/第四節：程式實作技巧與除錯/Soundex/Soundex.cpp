#include<iostream>
using namespace std;

int code[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};

int main(){
	
	string s;
	
	while(cin >> s){
		
		for(int i=0;i<(int)s.size();i++){
			
			if(code[s[i]-'A']){
				
				if(i){
					
					if(code[s[i]-'A'] != code[s[i-1]-'A'])
						cout << code[s[i]-'A'];
					
				}
				
				else
					cout << code[s[i]-'A'];
				
			}
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}