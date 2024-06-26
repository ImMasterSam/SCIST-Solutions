#include<iostream>
#include<iomanip>
#define _USE_MATH_DEFINES
#include<cmath>
using namespace std;

double p, q, r, s, t, u;
const double ESP = 1e-9;

double func(double x){
	
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x, 2)+u;
	
}

double BinarySearch(){
	
	double l=0, r=1+ESP;
	
	while(r-l>ESP){
		
		double mid = (l+r)/2;
		
		if(func(mid) > 0)
			l = mid;
		else
			r = mid;
		
	}
	
	return (l+r)/2;
	
}


int main(){
	
	while(cin >> p >> q >> r >> s >> t >> u){
		
		if(func(0)*func(1) > 0)
			cout << "No solution\n";
		
		else
			cout << fixed << setprecision(4) << BinarySearch() << "\n";
		
	}
	
	
	return 0;
}