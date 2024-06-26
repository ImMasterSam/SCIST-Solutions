#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	long long arr[n];
	long long dp[n][n] = {0};
	
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	long long pre[n+1] = {0};
	
	for(int i=1;i<=n;i++){
		
		pre[i] = pre[i-1] + arr[i-1];
		
	}
		
	for(int len=2;len<=n;len++){
		
		for(int i=0;i+len-1<n;i++){
			
			int j = i + len - 1;
			long long MIN = LLONG_MAX;
			
			for(int k=i;k<j;k++){
				
				MIN = min(MIN, dp[i][k] + dp[k+1][j] + (pre[j+1] - pre[i]));
				
			}
			
			dp[i][j] = MIN;
			
		}
		
	}
	
	cout << dp[0][n-1] << "\n";
	
	return 0;
}
