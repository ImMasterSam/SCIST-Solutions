#include <iostream>
using namespace std;

int main(){
	int a, b, n;
	cin >> a >> b >> n;
	
	if(n>=a && n<=b)
		cout << "yes\n";
	else
		cout << "no\n";
		
	return 0;
}

