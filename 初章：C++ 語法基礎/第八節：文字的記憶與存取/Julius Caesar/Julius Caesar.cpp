#include<iostream>
using namespace std;

int main(){
	
	int t, c;
	cin >> t;
	string s;
	cin >> s;
	
	for(int i=0;i<s.size();i++){
		
		c = s[i]-t;
		while(c<'A')
			c += 26;
		cout << (char)c;
		
	}
	
	cout << "\n";
		
	return 0;
}