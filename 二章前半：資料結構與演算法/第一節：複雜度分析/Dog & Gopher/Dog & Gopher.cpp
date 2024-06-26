#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	
	double dx, dy, gx, gy, hx, hy;
	
	cin >> gx >> gy >> dx >> dy;
	
	cout << fixed << setprecision(3);
	
	bool through = false;
	
	while(cin >> hx >> hy){
		
		double d, g;
		
		d = sqrt(pow(abs(hx-dx), 2) + pow(abs(hy-dy), 2));
		g = sqrt(pow(abs(hx-gx), 2) + pow(abs(hy-gy), 2));
		
		//cout << d << " " << g << "\n";
		
		if(2*g <= d){
			cout << "The gopher can escape through the hole at (" << hx << "," << hy << ").\n";
			through = true;
		}
			
		
	}
	
	if(!through)
		cout << "The gopher cannot escape.\n";
	
	
	return 0;
}