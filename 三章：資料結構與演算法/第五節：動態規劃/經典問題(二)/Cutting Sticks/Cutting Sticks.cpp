#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int l, n;
	
	while(cin >> l, l){
		
		cin >> n;
		int pre[n+2] = {0};
		
		for(int i=1;i<=n;i++){
			
			int c;
			cin >> c;
			pre[i] = c;
			
		}
		pre[n+1] = l;
		
		int dp[n+2][n+2] = {0};
		
		for(int len=2;len<=n+1;len++){
			
			for(int i=1;i+len-1<=n+1;i++){
				
				int MIN = INT_MAX;
				int j = i+len-1;
				
				for(int k=i;k<j;k++){
					
					MIN = min(MIN, dp[i][k] + dp[k+1][j] + (pre[j] - pre[i-1]));
					
				}
				
				dp[i][j] = MIN;
				
			}
			
		}
		
		cout << "The minimum cutting is " << dp[1][n+1] << ".\n";
		
	}
	
	return 0;
}
