#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp (205, vector<vector<int>> (205, vector<int> (3, -1)));

void print(int n, int k){
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=k;j++){
			
			cout << dp[i][j][0] << "," << dp[i][j][1] << "," << dp[i][j][2] << " : ";
			
		}
		
		cout << "\n";
		
	}
	
}

int main(){
	
	int n, k;
	cin >> n >> k;
	
	int left[n], right[n];
	
	for(int i=0;i<n;i++)
		cin >> left[i] >> right[i];
	
	int trash;
	cin >> trash >> trash;
	
	dp[0][0][0] = left[0] + right[0];
	dp[0][1][1] = left[0];
	dp[0][1][2] = right[0];
	
	for(int i=1;i<n;i++){
		
		for(int j=0;j<=k && j<=i+1;j++){
			
			if(max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) >= 0)
				dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) + left[i] + right[i];
			
			if(j){
				
				if(max(dp[i-1][j-1][0], dp[i-1][j-1][1]) >= 0)
					dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j-1][1]) + left[i];
				if(max(dp[i-1][j-1][0], dp[i-1][j-1][2]) >= 0)
				dp[i][j][2] = max(dp[i-1][j-1][0], dp[i-1][j-1][2]) + right[i];
				
			}
			
		}
		
		//print(n, k);
		
	}
	
	cout << max(dp[n-1][k][0], max(dp[n-1][k][1], dp[n-1][k][2])) << "\n";
	
	return 0;
}