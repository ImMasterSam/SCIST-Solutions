#include<iostream>
using namespace std;

int dp[100] = {0};
int used[100] = {0};

int stair(int n){
	
	if(used[n])
		return dp[n];
		
	used[n] = 1;
	
	if(n<=1)
		dp[n] = 1;
	else{
		
		dp[n] = stair(n-1) + stair(n-2);
		
	}
	
	return dp[n];
	
}

int main(){
	
	int n;
	cin >> n;
	cout << stair(n);
		
	return 0;
}