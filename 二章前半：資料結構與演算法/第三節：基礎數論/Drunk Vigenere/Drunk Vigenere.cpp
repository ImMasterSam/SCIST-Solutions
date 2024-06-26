#include<iostream>
using namespace std;

int main(){
	
	string c;
	string k;
	
	char ch;
	
	cin >> c >> k;
	
	string ans = "";
	
	for(int i=0;i<(int)c.size();i++){
		
		if(i%2)
			ch = ((c[i]-'A') + (k[i]-'A'))%26 + 'A';
		else
			ch = ((c[i]-'A') - (k[i]-'A') + 26)%26 + 'A';
			
		ans += ch;
		
	}
	
	cout << ans;
	
	
	return 0;
}