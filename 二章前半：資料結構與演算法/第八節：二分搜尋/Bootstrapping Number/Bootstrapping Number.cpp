#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double ESP = 1e-9;

double BinarySearch(double n){
	
	double l = 1, r = 11;
	
	while(r-l > ESP){
		
		double mid = (l+r)/2;
		
		if(pow(mid, mid) < n)
			l = mid;
		else
			r = mid;
		
	}
	
	
	return (l+r)/2;
}

int main(){
	
	double n;
	cin >> n;
	
	cout << fixed << setprecision(8) << BinarySearch(n);
	
	return 0;
}