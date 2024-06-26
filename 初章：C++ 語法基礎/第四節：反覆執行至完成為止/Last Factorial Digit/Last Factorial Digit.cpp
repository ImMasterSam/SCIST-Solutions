#include <iostream>
using namespace std;

int main(){
	int t, n, fac;
	cin >> t;
	for(int i=0;i<t;i++){
		fac = 1;
		cin >> n;
		for(int j=2;j<=n;j++)
			fac *= j;
		
		cout << fac%10 << "\n";
		
	}
	return 0;
}

