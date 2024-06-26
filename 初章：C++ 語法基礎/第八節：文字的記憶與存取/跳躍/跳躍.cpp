#include<iostream>
using namespace std;

int main(){
	
	int n, pos;
	string s;
	char d;

	cin >> n;
	cin >> s;
	cin >> d;
	
	for(int i=0;i<n;i++){
		
		if(s[i]=='P')
			pos = i;
	
	}
	
	if(d == 'L')
		pos--;
	else
		pos++;
		
	for(int i=0;i<n;i++){
		
		if(i != pos)
			cout << ".";
		else
			cout << "P";
	
	}
	
	cout << "\n";
	
		
	return 0;
}