#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	long long n, x;
	cin >> n;
	
	for(long long i=0;i<n;i++){
		
		cin >> x;
		double rec = 0.0;
		
		for(int j=2;j<=x;j++)
		rec += log10(j);
		
		cout << (int)rec+1 << "\n";
	}
		
	return 0;
}