#include<iostream>
#include<cmath>
using namespace std;

int dp[50] = {0};
int used[50] = {0};

int stair(int n){
	
	if(used[n]){
		
		return dp[n];
		
	}
	
	used[n] = 1;
	
	if(n <= 1){
		
		dp[n] = 1;
		
	}
	else if(n <= 2){
		
		dp[n] = stair(n-1);
		
	}
	else if(n <= 3){
		
		dp[n] = stair(n-1) + stair(n-3);
		
	}
	else{
		
		dp[n] = stair(n-1) + stair(n-3) + stair(n-4);
		
	}
	
	return dp[n];
	
}

int main(){
	
	int n;
	cin >> n;
		
	cout << stair(n);
	
	
	return 0;
}