#include<iostream>
using namespace std;

int main(){
	
	char s[105];
	cin >> s;
	
	cout << s[0];
	
	for(int i=0;i<105;i++){
		
		if(s[i] == '-')
			cout << s[i+1];
	}
	
	return 0;
}