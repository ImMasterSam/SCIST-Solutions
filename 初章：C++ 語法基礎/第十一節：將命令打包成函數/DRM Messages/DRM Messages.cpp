#include<iostream>
using namespace std;

string Encrypt(string s){
	
	int sum=0;
	for(int i=0;i<(int)s.size();i++)
		sum += s[i]-'A';
	
	string re="";
	char c;

	for(int i=0;i<(int)s.size();i++){
		c = s[i]+sum%26;
		while(c>'Z')
			c -= 26;
		re += (char) c;
	}
	
	return re;
	
}

int main(){
	
	string s, a, b;
	cin >> s;
	
	a = Encrypt(s.substr(0, s.size()/2));
	b = Encrypt(s.substr(s.size()/2, s.size()/2));
	
	char c;
	for(int i=0;i<(int)s.size()/2;i++){
		c = a[i]+(b[i]-'A')%26;
		while(c>'Z')
			c -= 26;
		cout << c;
	}
	
	return 0;
}