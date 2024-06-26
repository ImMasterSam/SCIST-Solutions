#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
long long dp[100005][105] = {0};

int main(){
	
	int n, m;
	cin >> n >> m;
	
	long long arr[n];
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		
	}
	
	if(arr[0])
		dp[0][arr[0]] = 1;
	else{
		
		for(int i=1;i<=m;i++){
			
			dp[0][i] = 1;
			
		}
		
	}
	
	for(int i=1;i<n;i++){
		
		if(arr[i]){
			
			int num = arr[i];
			
			for(int k=-1;k<=1;k++){
				
				if(num+k<1 || num+k>m) continue;
				
				dp[i][num] = (dp[i][num] + dp[i-1][num+k]) % MOD;
				
			}
			
		}
		else{
			
			for(int j=1;j<=m;j++){
				
				for(int k=-1;k<=1;k++){
					
					if(j+k<1 || j+k>m) continue;
					
					dp[i][j] = (dp[i][j] + dp[i-1][j+k]) % MOD;
					
				}
					
			}
			
		}
		
		
	}
	
	long long ans = 0;
		
		for(int i=1;i<=m;i++)
			ans = (ans + dp[n-1][i]) % MOD;
			
		cout << ans;
	
	return 0;
}