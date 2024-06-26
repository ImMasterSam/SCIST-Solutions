#include <iostream>
using namespace std;

int main(){
	int a, b, n;
	cin >> a >> b;
	
	n = a-b;
	if(n>0)
		cout << n << "\n";
	else
		cout << -n << "\n";
		
	return 0;
}

