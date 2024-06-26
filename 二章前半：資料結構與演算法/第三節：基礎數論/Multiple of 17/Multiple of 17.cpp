#include<iostream>
using namespace std;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		if(s == "0")
			break;
			
		int n = 0;
		
		for(int i=0;i<(int)s.size();i++){
			
			n = (n*10 + (s[i]-'0'))%17;
			
		}
		
		if(n)
			cout << "0\n";
		else
			cout << "1\n";
		
	}
	
	return 0;
}