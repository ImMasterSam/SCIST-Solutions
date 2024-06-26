#include <iostream>
using namespace std;

int main(){
	long long e, f, c, d=0;
	cin >> e >> f >> c;
	while((e+f) >= c){
		d += (e+f)/c;
		e = e-c*((e+f)/c) + ((e+f)/c);
	}
	
	cout << d << "\n";
	
	return 0;
}

