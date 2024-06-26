#include <bits/stdc++.h>
using namespace std;

int arr[1000005], dp[1000005][2] = {0};

int main(){
	
	int n;
	while(cin >> n){
		
		for(int i=0;i<n;i++){
			
			cin >> arr[i];
			dp[i][0] = dp[i][1] = 0;
			
		}
			
		dp[0][1] = arr[0];
		
		for(int i=1;i<n;i++){
			
			dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
			dp[i][1] = max(dp[i-1][1], dp[i-1][0] + arr[i]);
			
		}
		
		cout << max(dp[n-1][1], dp[n-1][0]) << "\n";
		
	}
		
	
	return 0;
}