#include<iostream>
using namespace std;

int dp[100][2] = {0};
int used[100] = {0};

int solve(int n, int i){
	
	if(used[n]){
		
		return dp[n][i];
		
	}
	
	used[n] = 1;
	
	if(n == 1){
		
		dp[n][1] = 1;
		dp[n][0] = 0;
		
	}
		
	else if(n == 2){
		
		dp[n][1] = 1;
		dp[n][0] = 1;
		
	}
		
	else{
		
		dp[n][0] = solve(n-1, 1);
		dp[n][1] = solve(n-2, 0)+solve(n-2, 1);
		
	}
	
	return dp[n][i];
	
} 



int main(){
	
	int n;
	
	while(cin >> n){
		
		cout << solve(n, 0) + solve(n, 1) << "\n";
		
	}
	
	
	return 0;
}