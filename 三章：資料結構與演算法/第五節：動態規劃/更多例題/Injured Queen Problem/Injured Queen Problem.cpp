#include <bits/stdc++.h>
using namespace std;

long long dp[15][15] = {0};
map<char, int> alpha = {{'1', 0}, {'2', 1}, {'3', 2}, {'4', 3}, {'5', 4},
						{'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'A', 9},
						{'B', 10}, {'C', 11}, {'D', 12}, {'E', 13}, {'F', 14}};

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	
	while(cin >> s){
		
		memset(dp, 0, sizeof dp);
		int n = s.size();
		
		if(s[0] == '?'){
			
			for(int i=0;i<n;i++){
				
				dp[0][i] = 1;
				
			}
			
		}
		else{
			
			dp[0][alpha[s[0]]] = 1;
			
		}
		
		for(int i=1;i<n;i++){
			
			if(s[i] == '?'){
				
				for(int j=0;j<n;j++){
					
					for(int k=0;k<n;k++){
						
						if(abs(j-k) <= 1) continue;
						dp[i][j] += dp[i-1][k];
						
					}
					
				}
				
			}
			else{
				
				int idx = alpha[s[i]];
				for(int k=0;k<n;k++){
					
					if(abs(idx-k) <= 1) continue;
					dp[i][idx] += dp[i-1][k];
					
				}
				
			}
			
		}
		
		long long ans = 0;
		
		for(int i=0;i<n;i++){
			
			ans += dp[n-1][i];
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}