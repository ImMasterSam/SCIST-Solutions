#include<iostream>
using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	
	if((a*b)%2==0)
		cout << "even";
	else
		cout << "odd"; 
	
	return 0;
}