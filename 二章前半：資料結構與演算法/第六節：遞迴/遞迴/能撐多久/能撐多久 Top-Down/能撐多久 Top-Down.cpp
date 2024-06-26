#include<iostream>
using namespace std;

int devide(int a, int b){
	
	if(a == 0)
		return 0;
	else
		return devide(a/b, b) + 1;
	
}

int main(){
	
	int a, b;
	
	cin >> a >> b;
	
	cout << devide(a, b);
	
	
	return 0;
}