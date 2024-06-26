#include <iostream>
using namespace std;

int main(){
	long long n, min=1000000001, index;
	cin >> n;
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	for(int i=0;i<n;i++){
		if(a[i] < min){
			index = i;
			min = a[i];
		}
	}
	
	cout << index << "\n";
	
	return 0;
}

