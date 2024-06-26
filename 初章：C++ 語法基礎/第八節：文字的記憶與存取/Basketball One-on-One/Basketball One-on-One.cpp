#include<iostream>
using namespace std;

int main(){
	
	char s[205];
	cin >> s;
	
	int a=0, b=0;
	
	for(int i=0;i<205;i+=2){
		
		if(s[i]=='A')
			a += s[i+1]-'0';
		else if(s[i]=='B')
			b += s[i+1]-'0';
		
	}
	
	//cout << a << ":" << b << "\n";
	
	if(a>b)
		cout << "A";
	else
		cout << "B";
	
	return 0;
}