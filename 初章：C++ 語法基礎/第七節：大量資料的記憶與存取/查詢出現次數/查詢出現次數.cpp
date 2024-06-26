#include <iostream>
using namespace std;

int a[1001] = {0};

int main(){
	int n, x, d;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> x;
		a[x]++;
	}
	
	cin >> d;
	printf("%d appears %d times.", d, a[d]);
	
	return 0;
}

