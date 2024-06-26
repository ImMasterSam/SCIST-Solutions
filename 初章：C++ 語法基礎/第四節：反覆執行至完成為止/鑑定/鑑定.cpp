#include <iostream>
using namespace std;

int main(){
	int n, l=0;
	cin >> n;
	
	while(n){
		n /= 10;
		l++;
	}
	
	cout << l << "\n";
	
	return 0;
}

