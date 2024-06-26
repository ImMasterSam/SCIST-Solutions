#include <bits/stdc++.h>
using namespace std;

int dp[51][4];

int main(){
	
	int n;
	cin >> n;
	
	for(int i=0;i<4;i++)
		dp[0][i] = 1;
		
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=3;j++){
			
			if(i-j < 0)
				continue;
			
			for(int k=1;k<=3;k++){
				
				if(i-j == 0){
					
					dp[i][j] += 1;
					break;
					
				}
				
				if(k == j)
					continue;
				
				dp[i][j] += dp[i-j][k];
				
			}
			
		}
		
	}
	
	cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	
	return 0;
}