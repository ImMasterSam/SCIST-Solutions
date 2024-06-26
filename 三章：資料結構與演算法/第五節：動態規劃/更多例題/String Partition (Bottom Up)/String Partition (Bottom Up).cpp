#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[205], sum[205][205];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	while(n--){
		
		memset(dp, 0, sizeof dp);
		memset(sum, 0, sizeof sum);
		
		cin >> s;
		
		for(int i=0;i<s.size();i++){
			
			long long res = 0;
			
			for(int j=i;j<s.size();j++){
				
				res = res*10 + s[j]-'0';
				
				if(res > INT_MAX)
					break;
					
				sum[i][j] = res;
				
			}
			
		}
		
		for(int i=0;i<s.size();i++){
			
			dp[i] = sum[0][i];
			
			for(int j=max(1, i-10);j<=i;j++){
				
				dp[i] = max(dp[i], dp[j-1] + sum[j][i]);
				
			}
			
		}
		
		cout << dp[s.size()-1] << "\n";
		
	}
	
	return 0;
}