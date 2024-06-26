#include <bits/stdc++.h>
using namespace std;

unsigned long long dp[102][102] = {0};

unsigned long long combination(int n, int m){
	
	if(dp[n][m])
		return dp[n][m];
	
	if(m==1 || m==n)
		return dp[n][m] = 1;
	
	return dp[n][m] = combination(n-1, m-1) + combination(n-1, m);;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	
	while(cin >> n >> m, (n || m)){
		
		cout << n << " things taken " << m << " at a time is " << combination(n+1, m+1) << " exactly.\n";
		
	}
	
	return 0;
}