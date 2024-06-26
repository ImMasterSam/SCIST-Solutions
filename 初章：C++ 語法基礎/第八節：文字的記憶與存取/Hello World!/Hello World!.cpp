#include<iostream>
using namespace std;

int main(){
	
	string s;
	getline(cin, s);
	
	cout << "Hello ,";
	
	for(int i=0;i<s.size();i++)
		if(i==s.size()-1 && s[i]==' ')
			continue;
		else
			cout << s[i];
		
	cout << " !\n";
	
	return 0;
}