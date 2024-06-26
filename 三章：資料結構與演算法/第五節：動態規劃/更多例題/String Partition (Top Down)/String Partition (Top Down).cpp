#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[205], sum[205][205];

long long DP(int size){
	
	//cout << size << "\n";
	
	if(dp[size])
		return dp[size];
	
	if(size == 0)
		return 0;
	
	long long res = 0;
	
	for(int k=max(0, size-10);k<size;k++){
		
		long long part = sum[k][size-1];
		
		if(part <= INT_MAX){
			
			res = max(res, DP(k)+part);
			
		}
		
	}
	
	return dp[size] = res;
	
} 

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
		
		cout << DP(s.size()) << "\n";
		
	}
	
	return 0;
}