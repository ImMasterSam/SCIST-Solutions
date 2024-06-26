#include <bits/stdc++.h>
using namespace std;

double dp[100][10] = {0};
/*
void print(int n, int k){
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<=k;j++){
			
			cout << setw(5) << dp[i][j] << " ";
			
		}
		
		cout << "\n";
		
	}
	
}
*/
int main(){
	
	int n, k;
	
	while(cin >> k >> n){
		
		memset(dp, 0, sizeof dp);
		
		double total = pow(k+1, n);
		double avail = 0;
		
		for(int i=0;i<=k;i++)
			dp[0][i] = 1;
		
		for(int i=1;i<n;i++){
			
			for(int j=0;j<=k;j++){
				
				for(int l=-1;l<=1;l++){
					
					if(j + l < 0 || j + l > k)
						continue;
						
					dp[i][j] += dp[i-1][j + l];
					
				}
				
			}
			
			//print(n, k);
			
		}
		
		for(int i=0;i<=k;i++)
			avail += dp[n-1][i];
		
		//cout << avail << " : " << total << "\n";
		cout << fixed << setprecision(5) << (avail/total)*100 << "\n";
		
	}
	
	return 0;
}