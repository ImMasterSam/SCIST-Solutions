#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int coin[5] = {1, 5, 10, 25, 50};

long long dp[10000] = {0};

int main(){ BOOST
	
	dp[0] = 1;
	
	for(int i=0;i<5;i++){
			
		for(int j=coin[i];j<=10000;j++)
			dp[j] += dp[j - coin[i]];
		
	}
	
	int n;
	
	while(cin >> n){
		
		cout << dp[n] << "\n";
		
	}
	
	return 0;
}
