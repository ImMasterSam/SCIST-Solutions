#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		if(s == "0")
			break;
		
		long long odd=0, even=0;
		
		for(int i=0;i<(int)s.size();i++){
			
			if(s[i]>='0' && s[i]<='9'){
				
				cout << s[i];
				
				if(i%2)
					odd += s[i] - '0';
				else
					even += s[i] - '0';
				
			}
			
		}
		
		if(abs(odd-even)%11 == 0)
			cout << " is a multiple of 11.\n";
		else
			cout << " is not a multiple of 11.\n";
		
	}
	
	return 0;
}