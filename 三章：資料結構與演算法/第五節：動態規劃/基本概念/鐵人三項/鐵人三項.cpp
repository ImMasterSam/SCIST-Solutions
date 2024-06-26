#include <bits/stdc++.h>
using namespace std;

int arr[200005][3] = {0};
vector<vector<long long>> dp(200005, vector<long long> (3, LLONG_MAX));
/*
void print(int n){
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<3;j++)
			cout << setw(20) << dp[i][j] << " ";
		cout << "\n";
		
	}
	
	cout << "\n";
	
}
*/
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<3;j++)
			cin >> arr[i][j];
		
	}
	
	dp[0][0] = arr[0][0];
	
	for(int i=1;i<n;i++){
		
		for(int j=0;j<3;j++){
			
			if(j == 0)
				dp[i][j] = dp[i-1][j] + arr[i][j];
			
			else{
				
				long long MIN = min(dp[i-1][j], dp[i-1][j-1]);
				
				if(MIN != LLONG_MAX)
					dp[i][j] = MIN + arr[i][j];
				
			}
			
		}
		
	}
	
	
	cout << dp[n-1][2] << "\n";
	
	return 0;
}