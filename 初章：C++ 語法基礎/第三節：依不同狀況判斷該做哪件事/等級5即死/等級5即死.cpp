#include <iostream>
using namespace std;

int main(){
	int p, q, d=0, t=0;
	cin >> p >> q;
	if(p%2==0)
		d++;
	if(p%3==0)
		t++;
	if(q%2==0)
		d++;
	if(q%3==0)
		t++;
	
	cout << d << " " << t << "\n";

	return 0;
}

