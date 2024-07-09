#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

long long comb2(long long n){
	
	return (n*(n-1)) / 2;
	
}

int main(){ BOOST

	map<long long, long long> MAP;
	
	long n;
	cin >> n;
	
	for(int i=0, x;i<n;i++){
		
		cin >> x;
		MAP[x]++;
		
	}
	
	long long ans = comb2(n);
	for(auto it=MAP.begin();it!=MAP.end();it++){
		
		if(it->second >= 2){
			
			ans -= comb2(it->second);
			
		}
		
	}
	
	cout << ans << "\n";
	
	return 0;
}
