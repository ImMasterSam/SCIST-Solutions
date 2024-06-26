#include<iostream>
using namespace std;

int main(){
	
	int n, p;
	cin >> n;
	string s[10], name;
	
	for(int i=0;i<n;i++){
		
		cin >> name >> p;
		s[p-1] = name;
		
	}
	
	for(int i=0;i<10;i++){
		
		if(s[i]=="")
			cout << "EMPTY\n";
		else
			cout << s[i] << "\n";
		
	}
		
	return 0;
}