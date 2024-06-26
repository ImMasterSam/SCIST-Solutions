#include<iostream>
#include<cmath>
using namespace std;

const double ESP = 1e-7;

int main(){
	
	double	a, b, c, d;
	double diff;
	
	cin >> a >> b >> c >> d;
	diff = fabs(a*d-b*c);
	
	if(diff<ESP)	
		cout << "0\n";
	else
		cout << "1\n";
	
	return 0;
}