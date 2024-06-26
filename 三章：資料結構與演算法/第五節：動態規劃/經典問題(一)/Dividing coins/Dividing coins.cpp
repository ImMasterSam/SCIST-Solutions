#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool dp[105][60000];
int arr[105];

int main(){ //BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		int m;
		cin >> m;
		
		if(m == 0){
			
			cout << 0 << "\n";
			continue;
			
		}
		
		int sum = 0;
		for(int i=0;i<m;i++){
			
			cin >> arr[i];
			sum += arr[i];
			
		}
		
		memset(dp, false, sizeof dp);
		dp[0][0] = dp[0][arr[0]] = true;
		
		for(int i=1;i<m;i++){
			
			for(int j=0;j<=sum/2;j++){
				
				dp[i][j] = dp[i][j] || dp[i-1][j];
				
				if(j - arr[i] >= 0)
					dp[i][j] = dp[i][j] || dp[i-1][j - arr[i]];
				
			}
			
		}
		
		for(int i=sum/2;i>=0;i--){
			
			if(dp[m-1][i]){
				
				cout << abs((sum-i) - i) << "\n";
				break;
				
			}
			
		}
		
	}
	
	return 0;
}
