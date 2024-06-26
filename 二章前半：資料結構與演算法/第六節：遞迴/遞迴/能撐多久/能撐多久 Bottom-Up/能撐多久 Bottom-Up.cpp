#include<iostream>
using namespace std;

int devide(int a, int b){
	
	int count = 0;
	
	while(a){
		
		a /= b;
		count++;
		
	}
	
	return count;
	
}

int main(){
	
	int a, b;
	
	cin >> a >> b;
	
	cout << devide(a, b);
	
	return 0;
}