#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double PI = acos(-1);

int main(){
	
	int n, m;
	cin >> n;
	
	double degree, dis, rad;
	
	for(int t=0;t<n;t++){
		
		double vx = 0.0, vy = 1.0;
		double tvx, tvy;
		double x = 0.0, y = 0.0;
		
		cin >> m;
		for(int time=0;time<m;time++){
			cin >> degree >> dis;
			
			rad = degree/180*PI;
			
			tvx = vx*cos(rad) - vy*sin(rad);
			tvy = vx*sin(rad) + vy*cos(rad);
			
			vx = tvx; vy = tvy;
			
			x += tvx*dis;
			y += tvy*dis;
			
		}
		
		cout << fixed << setprecision(6) << x << " " << y << "\n";
		
	}
	
	return 0;
}