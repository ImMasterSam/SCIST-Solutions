#include<iostream>
using namespace std;

int main(){
	
	char c;
	cin >> c;
	
	if(c=='A')
		cout << "@\n";
	else
		cout << (char)(c-1) << "\n";
		
	return 0;
}