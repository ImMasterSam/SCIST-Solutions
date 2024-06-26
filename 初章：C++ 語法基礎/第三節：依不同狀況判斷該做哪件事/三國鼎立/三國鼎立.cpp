#include <iostream>
using namespace std;

int main(){
	int p, q, r;
	cin >> p >> q >> r;
	
	if(p+q<r)
		cout << "no\n";
	else if(p+r<q)
		cout << "no\n";
	else if(q+r<p)
		cout << "no\n";
	else
		cout << "yes\n";
		
	return 0;
}

