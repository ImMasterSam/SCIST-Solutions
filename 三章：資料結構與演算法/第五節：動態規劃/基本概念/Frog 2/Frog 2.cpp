#include <bits/stdc++.h>
using namespace std;

int h[100005] = {0};
int dp[100005] = {0};

int main(){
	
	int n, k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> h[i];
		
	for(int i=1;i<n;i++){
		
		int MIN = INT_MAX;
		
		for(int j=1;j<=k;j++){
			
			if(i-j < 0)
				break;
			
			MIN = min(MIN, dp[i-j] + abs(h[i] - h[i-j]));
			
		}
		
		dp[i] = MIN;
		
	}
	
	cout << dp[n-1] << "\n";
	
	return 0;
}