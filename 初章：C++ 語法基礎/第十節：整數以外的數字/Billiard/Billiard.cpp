#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double PI=acos(-1);

int main(){
	
	long long a, b, s, m, n;
	cin >> a >> b >> s >> m >> n;
	
	double h, w;
	while(a!=0){
		w = 2*m*(a/2.0);
		h = 2*n*(b/2.0);
		
		//cout << w << " " << h << "\n";
		
		cout << fixed << setprecision(2) << atan2(h, w)/PI*180 << " ";
		cout << fixed << setprecision(2) << sqrt(w*w+h*h)/s << "\n";
		
		cin >> a >> b >> s >> m >> n;
	}
		
	return 0;
}