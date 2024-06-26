#include <bits/stdc++.h>
using namespace std;

int arr[100];
bool dp[100][10] = {0};
bool used[100][10] = {0};

bool DP(int stair, int r){
	
	if(stair <= 1)
		return dp[stair][r];
	
	if(used[stair][r]){
		
		return dp[stair][r];
		
	}
	
	used[stair][r] = true;
	
	int temp = 10 - (arr[stair] - r + 10)%10;
	
	return dp[stair][r] = DP(stair-1, temp) || DP(stair-2, temp);
	
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	
	dp[1][arr[1]%10] = true;
		
	for(int i=0;i<10;i++){
		
		if(DP(n, i)){
			
			cout << i << "\n";
			break;
			
		}
		
	}
	
	return 0;
}