#include<iostream>
using namespace std;

int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	int fib[10000] = {0, 1};
	
	for(int i=2;i<=n;i++){
		
		fib[i] = (fib[i-1]+fib[i-2])%m;
		
	}
	
	cout << fib[n] << "\n";
		
	return 0;
}