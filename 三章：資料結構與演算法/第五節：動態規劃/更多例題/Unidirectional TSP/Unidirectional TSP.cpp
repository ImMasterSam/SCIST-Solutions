#include <bits/stdc++.h>
using namespace std;

long long dp[10][100];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, n;
	
	while(cin >> m >> n){
		
		long long arr[m][n];
		
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> arr[i][j];
				dp[i][j] = 0;
				
			}
			
		}
		
		for(int i=0;i<m;i++){
			
			dp[i][n-1] = arr[i][n-1];
			
		}
		
		for(int j=n-2;j>=0;j--){
			
			for(int i=0;i<m;i++){
				
				long long temp = LLONG_MAX;
				
				for(int k=-1;k<=1;k++){
						
					temp = min(temp, dp[((i+k)+m)%m][j+1]);
					
				}
				
				dp[i][j] = temp + arr[i][j];
				
			}
			
		}
		
		long long MIN = LLONG_MAX;
		int idx;
		
		for(int i=0;i<m;i++){
			
			if(dp[i][0] < MIN){
				
				MIN = dp[i][0];
				idx = i;
				
			}
			
		}
		
		cout << idx+1;
		
		for(int j=1;j<n;j++){
			
			long long temp = LLONG_MAX;
			int t_idx = idx;
			
			for(int k=-1;k<=1;k++){
				
				if(dp[((idx+k)+m)%m][j] < temp){
					
					temp = dp[((idx+k)+m)%m][j];
					t_idx = ((idx+k)+m)%m;
					
				}
				else if(dp[((idx+k)+m)%m][j] == temp){
					
					if(((idx+k)+m)%m < t_idx)
						t_idx = ((idx+k)+m)%m;
					
				}
				
			}
			
			idx = t_idx;
			cout << " " << idx+1;
			
		}
		
		cout << "\n" << MIN << "\n";
		
	}
	
	return 0;
}