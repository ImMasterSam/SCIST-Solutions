#include<iostream>
#include<iomanip>
using namespace std;

const double ESP = 1e-9;

double sqrt(double x){
	
	double l=0, r=x+1;
	
	while(r-l>ESP){
		
		double mid = (l+r)/2;
		
		if(mid*mid<x)
			l = mid;
		else
			r = mid;
		
	}
	
	return (l+r)/2;
	
}

int main(){
	
	double x;
	cin >> x;
	
	cout << fixed << setprecision(6) << sqrt(x);
	
	return 0;
}