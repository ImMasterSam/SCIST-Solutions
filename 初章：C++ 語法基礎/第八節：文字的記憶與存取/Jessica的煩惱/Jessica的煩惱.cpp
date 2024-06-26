#include<iostream>
using namespace std;

int main(){
	
	int t;
	string s;
	cin >> t >> s;
	
	for(int i=0;i<t;i++){
		
		if(s[i]<='Z')
			cout << (char)(tolower(s[i]));
		else if(s[i]>='a')
			cout << (char)(toupper(s[i]));
		
	}
	cout << "\n";
		
	return 0;
}