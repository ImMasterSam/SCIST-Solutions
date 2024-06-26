#include <bits/stdc++.h>
using namespace std;

long long dp[55][2];

int main(){
	
	int t;
	cin >> t;
	
	for(int time=1;time<=t;time++){
		
		memset(dp, 0, sizeof dp);
		
		int n;
		cin >> n;
		
		dp[0][1] = dp[0][0] = 1;
		
		for(int i=1;i<n;i++){
			
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
			
		}
		
		cout << "Scenario #" << time << ":\n";
		
		cout << dp[n-1][0] + dp[n-1][1] << "\n\n";
		
	}
	
	return 0;
}