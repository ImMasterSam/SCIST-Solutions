#include<iostream>
using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	
	if(a >= b)
		cout << 0;
	else
		cout << b-a+1;
	
	return 0;
}