#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


int main(){
	
	int n;
	cin >> n;
	
	long long man = 0;
	long long euc = 0;
	long long che = 0;
	long long x;
	
	for(int i=0;i<n;i++){
		cin >> x;
		
		man += abs(x);
		euc += x*x;
		
		if(abs(x)>che)
			che = abs(x);
		
	}
	
	cout << man << "\n";
	cout << fixed << setprecision(15) << sqrt(euc) << "\n";
	cout << che;
	
		
	return 0;
}