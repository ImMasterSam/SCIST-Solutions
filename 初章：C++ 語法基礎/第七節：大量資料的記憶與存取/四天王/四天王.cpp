#include <iostream>
using namespace std;

int a[4] = {0};

int main(){
	int n, x, d, max=-1, index = -1;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> x;
		a[x%4]++;
	}
	
	cout << "r2: " << a[2] << "\n";
	cout << "r1: " << a[1] << "\n";
	cout << "r3: " << a[3] << "\n";
	cout << "r0: " << a[0] << "\n";
	
	return 0;
}

