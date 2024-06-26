#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	
	while(cin >> n >> k){
		double ans = 0.0;
		
		if(k>=n/2)
			k = n-k;
			
		int i=1;
		while(i<=k){
			//cout << n << " " << i << "\n";
			ans += (log10(n--) - log10(i++));
		}
		
		
		
		cout << (int)ans+1 << "\n";
	}
	
	return 0;
}