#include <iostream>
using namespace std;

int main(){
	int p, q;
	cin >> p >> q;
	
	if(p%2==0 && q%2==0)
		cout << "yes\n";
	else if(p%2==1 && q%2==1)
		cout << "yes\n";
	else
		cout << "no\n";
		
	return 0;
}

