#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double n;
	
	while(cin >> n, n){
		
		int t = sqrt(n);
		
		if(t == sqrt(n))
			cout << "yes\n";
		else
			cout << "no\n";
		
	}
	
	return 0;
}