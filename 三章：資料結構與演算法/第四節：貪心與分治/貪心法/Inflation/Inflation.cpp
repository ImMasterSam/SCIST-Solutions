#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	int gas[n];
	
	for(int i=0;i<n;i++)	
		cin >> gas[i];
		
	sort(gas, gas+n);
	
	double f = 1.0;
	
	for(int i=0;i<n;i++){
		
		if(gas[i] > i+1){
			
			cout << "impossible";
			return 0;
			
		}
		
		else if(gas[i]/(double)(i+1) < f)
			f = gas[i]/(double)(i+1);
		
	}
	
	cout << fixed << setprecision(9) << f << "\n";
	
	
	return 0;
}