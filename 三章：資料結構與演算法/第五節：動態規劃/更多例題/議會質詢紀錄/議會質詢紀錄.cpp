#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

// 0: 0,0 1: 0,1 2: 0,2 3: 1,0 4: 1,1 5: 1,2 
long long dp[120005][6];
const long long MOD = 1e8+7;

int main(){ BOOST

	int n;
	
	while(cin >> n){
		
		memset(dp, 0, sizeof dp);
		
		dp[0][0] = dp[0][1] = dp[0][3] = 1;
		
		for(int i=1;i<n;i++){
			
			dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
			dp[i][1] = dp[i-1][0];
			dp[i][2] = dp[i-1][1];
			dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5]) % MOD;
			dp[i][4] = dp[i-1][3];
			dp[i][5] = dp[i-1][4];
			
		}
		
		long long ans = 0;
		
		for(int i=0;i<6;i++){
			
			ans = (ans + dp[n-1][i]) % MOD;
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
