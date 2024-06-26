#include<iostream>
using namespace std;

int cost[100] = {0};
int dp[100] = {0};
int used[100] = {0};

int stair(int n){
	
	if(used[n])
		return dp[n];
	
	used[n]++;
	
	if(n<=1)
		return cost[n];
	else
		dp[n] = min(stair(n-1), stair(n-2)) + cost[n];
	
	return dp[n];
	
}

int main(){
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> cost[i];
	
	cout << stair(n);
	
	return 0;
}