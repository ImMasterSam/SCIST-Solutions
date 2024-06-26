#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	if(n>=212)
		cout << 8;
	else if(n>=126)
		cout << 6;
	else
		cout << 4;
		
	return 0;
}