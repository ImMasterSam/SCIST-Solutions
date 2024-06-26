#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	int arr[n][3];
	
	for(int i=0;i<n;i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		
	int dp[n][3] = {0};
	
	for(int i=0;i<3;i++)
		dp[0][i] = arr[0][i];
	
	
	for(int i=1;i<n;i++){
		
		for(int j=0;j<3;j++){
			
			for(int k=0;k<3;k++){
				
				if(k == j)
					continue;
				
				dp[i][j] = max(dp[i][j], dp[i-1][k]);
				
			}
			
			dp[i][j] += arr[i][j];
			
		}
		
	}
	
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
	
	return 0;
}