#include <bits/stdc++.h>
using namespace std;

long long dp[1000005] = {0};
const long long MOD = 1e9+7;

long long DP(int n){
	
	if(dp[n])
		return dp[n];
		
	if(n <= 1)
		return dp[n] = 1;
	
	for(int i=-1;i>=-6 && n+i>=0;i--){
		
		dp[n] = (dp[n] + DP(n+i)) % MOD;
		
	}
	
	return dp[n];
	
}

int main(){
	
	int n;
	cin >> n;
	
	cout << DP(n);
	
	return 0;
}