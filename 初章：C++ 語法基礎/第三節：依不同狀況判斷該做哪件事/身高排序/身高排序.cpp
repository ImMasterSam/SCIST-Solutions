#include <iostream>
using namespace std;

int main(){
	int p, q;
	
	cin >> p >> q;
	
	if(p>q)
		cout << q << " " << p << "\n";
	else
		cout << p << " " << q << "\n";
		
	return 0;
}

