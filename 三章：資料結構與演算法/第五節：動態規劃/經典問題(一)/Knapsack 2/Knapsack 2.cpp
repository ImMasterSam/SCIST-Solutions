#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<vector<long long>> dp(100, vector<long long>(100010, INT_MAX));

int main(){ BOOST

	long long n, k;
	cin >> n >> k;
	
	long long w[n], v[n];
	for(int i=0;i<n;i++)
		cin >> w[i] >> v[i];
		
	dp[0][0] = 0;
	if(w[0] <= k)
		dp[0][v[0]] = w[0];
	
	for(int i=1;i<n;i++){
		
		for(int j=0;j<=100010;j++){
			
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			
			if(j - v[i] >= 0 && dp[i-1][j - v[i]] + w[i] <= k)
				dp[i][j] = min(dp[i][j], dp[i-1][j - v[i]]+w[i]);
			
		}
		
	}
	
	for(int i=100005;i>=0;i--){
		
		if(dp[n-1][i] < INT_MAX){
			
			cout << i << "\n";
			break;
			
		}
		
	}
	
	return 0;
}
