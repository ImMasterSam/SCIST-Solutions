#include <bits/stdc++.h>
using namespace std;

int dp[51][4] = {0};
bool used[51][4] = {0};

int DP(int stair, int last){
	
	if(used[stair][last]){
		
		return dp[stair][last];
		
	}
	
	used[stair][last] = true;
	
	if(stair == 0)
		return dp[stair][last] = 1;
	
	for(int i=1;i<=3;i++){
		
		if(i == last || stair-i < 0)
			continue;
			
		dp[stair][last] += DP(stair-i, i);
		
	}
	
	return dp[stair][last];
}

int main(){
	
	int n;
	int ans = 0;
	
	cin >> n;
	memset(dp, 0, sizeof dp);
	
	for(int i=1;i<=3;i++){
		
		if(n-i < 0)
			continue;
		
		ans += DP(n-i, i);
		
	}
	
	cout << ans << "\n";
	
	
	return 0;
}