#include<iostream>
using namespace std;

long long dp[50][2] = {0};

int main(){
	
	int k;
	cin >> k;
	
	dp[0][0] = 1;
	dp[1][1] = 1;
	
	for(int i=2;i<=k;i++){
		
		dp[i][0] = dp[i-1][1];
		dp[i][1] = dp[i-1][0] + dp[i-1][1];
		
	}
	
	cout << dp[k][0] << " " << dp[k][1];
	
		
	return 0;
}