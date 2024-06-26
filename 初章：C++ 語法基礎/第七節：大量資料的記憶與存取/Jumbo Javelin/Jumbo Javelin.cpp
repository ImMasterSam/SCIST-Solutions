#include <iostream>
using namespace std;

int main(){
	int n, l, sum=0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> l;
		sum += l;
	}
	
	cout << sum-(n-1);
	
	return 0;
}

