#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	string s;
	cin >> s;
	int r=1;
	
	int n = s.size();
	
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0 && i>r)
			r = i;
	}
	
	int c = n/r;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout << s[j*r+i];
	}
	
	return 0;
}