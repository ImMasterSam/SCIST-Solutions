#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	if(n==0)
		cout << "No";
	else if(n%100==0)
		cout << "Yes";
	else
		cout << "No";	
	
	return 0;
}