#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, p;
	cin >> n >> p;
	
	int arr[n];
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		arr[i] -= p;
		
	}
	
	int dp[n], MAX = 0;
	dp[0] = arr[0];
	
	for(int i=1;i<n;i++){
		
		dp[i] = max(0, dp[i-1]) + arr[i];
		MAX = max(MAX, dp[i]);
		
	}
	
	cout << MAX;
	
	return 0;
}
