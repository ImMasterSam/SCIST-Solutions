#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool dp[20][6010];

int main(){ BOOST

	int t;
	cin >> t;
	
	cin.ignore();
	
	while(t--){
		
		memset(dp, false, sizeof dp);
		
		string buffer;
		getline(cin, buffer);
		
		const char* ptr = buffer.c_str();
		int pos;
		
		int x, w[20], n = 0, sum = 0;
		
		while(sscanf(ptr, "%d%n", &x, &pos) != EOF){
			
			w[n++] = x;
			sum += x;
			ptr += pos;
			
		}
		
		if(sum & 1){
			
			cout << "NO\n";
			continue;
			
		}
		
		dp[0][0] = dp[0][w[0]] = true;
		
		for(int i=1;i<n;i++){
			
			for(int j=0;j<=sum;j++){
				
				if(j - w[i] >= 0)
					dp[i][j] |= dp[i-1][j - w[i]];
				
				dp[i][j]|=dp[i-1][j];
				
			}
			
		}
		
		cout << (dp[n-1][sum/2] ? "YES" : "NO") << "\n";
		
	}
	
	return 0;
}
