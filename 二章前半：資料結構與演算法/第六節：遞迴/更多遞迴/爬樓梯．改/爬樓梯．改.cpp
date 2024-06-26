#include<iostream>
#include<cmath>
using namespace std;

int dp[50] = {0};
int arr[50] = {0};
int used[50] = {0};

int stair(int n){
	
	if(used[n]){
		
		return dp[n];
		
	}
	
	used[n] = 1;
	
	if(n <= 1){
		
		dp[n] = arr[n];
		
	}
	else{
		
		dp[n] = min(stair(n-1), stair(n-2)) + arr[n];
		
	}
	
	return dp[n];
	
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> arr[i];
		
	cout << stair(n);
	
	
	return 0;
}