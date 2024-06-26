#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	vector<int> pre(n+1, 0);
	for(int i=1;i<=n;i++){
		
		int x;
		cin >> x;
		pre[i] = pre[i-1] + x;
		
	}
		
	vector<vector<int>> dp(n+1, vector<int> (n+1));
	
	for(int len=2;len<=n;len++){
		
		for(int i=1;i+len-1<=n;i++){
			
			int j = i + len - 1;
			int MIN = INT_MAX;
			
			for(int k=i;k<j;k++){
				
				MIN = min(MIN, dp[i][k] + dp[k+1][j] + abs((pre[k] - pre[i-1]) - (pre[j] - pre[k])));
				
			}
			
			dp[i][j] = MIN;
			
		}
		
	}
	
	cout << dp[1][n];
	
	return 0;
}
