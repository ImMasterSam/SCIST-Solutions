#include<iostream>
using namespace std;

int dp[100];
int cost[100] = {0};

int main(){
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> cost[i];
	
	dp[0] = 0;
	dp[1] = cost[1];
	
	for(int i=2;i<100;i++){
		
		dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
		
	}
	
	cout << dp[n];
			
	return 0;
}