#include<iostream>
using namespace std;

int a[3] = {1, 0, 0};

int main(){
	
	string s;
	cin >> s;
	
	int t;
	
	for(int i=0;i<s.size();i++){
		
		if(s[i]=='A'){
			t = a[0];
			a[0] = a[1];
			a[1] = t;
		}
		if(s[i]=='B'){
			t = a[1];
			a[1] = a[2];
			a[2] = t;
		}
		if(s[i]=='C'){
			t = a[0];
			a[0] = a[2];
			a[2] = t;
		}
		
	}
	
	for(int i=0;i<3;i++){
		if(a[i]==1)
			cout << i+1;
	}
		
	return 0;
}