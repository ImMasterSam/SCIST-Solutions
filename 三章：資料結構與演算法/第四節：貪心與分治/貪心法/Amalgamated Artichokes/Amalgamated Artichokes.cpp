#include <bits/stdc++.h>
using namespace std;

double p, a, b, c, d, n;

double price(int k){
	
	return p * (sin(a * k + b) + cos(c * k + d) + 2);
	
}

int main(){
	
	cin >> p >> a >> b >> c >> d >> n;
	
	double MAX = 0;
	double drop = 0;
	
	for(int i=1;i<=n;i++){
		
		double temp = price(i);
		
		if(temp > MAX)
			MAX = temp;
		else{
			
			if(MAX - temp > drop)
				drop = MAX - temp;
			
		}
		
	}
	
	cout << fixed << setprecision(9) << drop;
	
	
	return 0;
}