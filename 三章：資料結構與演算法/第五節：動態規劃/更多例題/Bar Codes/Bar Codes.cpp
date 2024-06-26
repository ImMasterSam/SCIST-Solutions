#include <bits/stdc++.h>
using namespace std;

long long dp[55][55][55] = {0};

int main(){
	
	int n, k, m;
	
	while(cin >> n >> k >> m){
		
		memset(dp, 0, sizeof dp);
		
		dp[0][1][1] = 1;
		
		for(int i=1;i<n;i++){
			
			for(int j=1;j<=k;j++){
				
				for(int l=1;l<=m;l++){
					
					dp[i][j][1] += dp[i-1][j-1][l];
					
				}
				
				for(int l=2;l<=m;l++){
					
					dp[i][j][l] += dp[i-1][j][l-1];
					
				}
				
			}
			
		}
		
		long long ans = 0;
		
		for(int i=1;i<=m;i++){
			
			ans += dp[n-1][k][i];
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}