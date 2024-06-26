#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

//0: up 1: down 2: arr

long long dp[100][100][100];

int main(){ BOOST

	int n;
	
	while(cin >> n){
		
		memset(dp, 0, sizeof dp);
		
		int arr[n][n];
		
		for(int i=0;i<n;i++)
			cin >> arr[0][i];
			
		for(int i=1;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				int x;
				cin >> x;
				arr[i][j] = arr[i-1][j] + x;
				
			}
			
		}
		
		long long MAX = LLONG_MIN;
		
		for(int i=0;i<n;i++){
			
			for(int j=i;j<n;j++){
				
				for(int k=0;k<n;k++){
					
					int temp = arr[j][k] - (i ? arr[i-1][k] : 0);
					
					if(k == 0){
						
						dp[i][j][k] = temp;
						MAX = max(MAX, dp[i][j][k]);
						
					}
					else{
						
						dp[i][j][k] = max((long long)0, dp[i][j][k-1]) + temp;
						MAX = max(MAX, dp[i][j][k]);
						
					}
						
					
				}
				
			}
			
		}
		
		cout << MAX << "\n";
		
	}
	
	return 0;
}
