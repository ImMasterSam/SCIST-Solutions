#include <bits/stdc++.h>
using namespace std;

int n, k;
bool dp[10005][105];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		memset(dp, false, sizeof dp);
		
		cin >> n >> k;
		
		int arr[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];
			
		int temp = abs(arr[0]);
			
		dp[0][temp%k] = true;
		dp[0][((-temp%k)+k)%k] = true;
		
		for(int i=1;i<n;i++){
			
			for(int j=0;j<k;j++){
				
				if(dp[i-1][j]){
					
					temp = abs(arr[i]);
					
					dp[i][(j+temp)%k] = true;
					dp[i][(((j-temp)%k)+k)%k] = true;
					
				}
				
			}
			
		}
		
		cout << (dp[n-1][0] ? "Divisible\n" : "Not divisible\n");
		
	}
	
	return 0;
}