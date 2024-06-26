#include<iostream>
using namespace std;

int f91(int n){
	
	if(n < 101)
		return 91;
	else
		return n-10;
	
}

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		cout << "f91(" << n << ") = " << f91(n) << "\n";
		
	}
	
	return 0;
}