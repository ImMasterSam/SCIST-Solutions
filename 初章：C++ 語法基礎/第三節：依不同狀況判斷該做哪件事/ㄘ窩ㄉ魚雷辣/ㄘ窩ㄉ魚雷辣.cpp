#include <iostream>
using namespace std;

int main(){
	int x0, x1, x2, x3;
	cin >> x0 >> x1 >> x2 >> x3;
	
	if(x2<=x1 && x3>=x0)
		cout << "yes\n";
	else
		cout << "no\n";
		
	return 0;
}

