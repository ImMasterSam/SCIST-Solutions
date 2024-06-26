#include<iostream>
using namespace std;

int main(){
	
	int a, b, min, max;
	cin >> a >> b;
	
	min = a;
	max = 6*a;
	
	if(b>=min && b<=max)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}