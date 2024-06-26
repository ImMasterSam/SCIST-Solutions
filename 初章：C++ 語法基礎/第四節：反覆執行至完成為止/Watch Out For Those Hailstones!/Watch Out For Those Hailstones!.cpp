#include <iostream>
using namespace std;

int main(){
	long long n, sum=0;
	cin >> n;
	
	while(n!=1){
		sum += n;
		if(n%2)
			n = 3*n + 1;
		else
			n /= 2;
	}
	
	cout << sum +1 << "\n";
	
	return 0;
}

