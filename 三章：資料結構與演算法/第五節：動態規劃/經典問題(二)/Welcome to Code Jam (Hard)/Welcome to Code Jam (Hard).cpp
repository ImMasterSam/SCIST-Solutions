#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

string target = "welcome to code jam";

int main(){ BOOST

	int t;
	cin >> t;
	cin.ignore();
	
	for(int time=0;time<t;time++){
		
		string s;
		getline(cin, s);
		
		int dp[target.size()][s.size()] = {0};
		
		for(int i=0;i<target.size();i++){
			
			for(int j=0;j<s.size();j++){
				
				int temp = 0;
				
				if(target[i] == s[j]){
					
					if(i && j)
						temp += dp[i-1][j-1];
					else if (i == 0)
						temp += 1;
					
				}
				
				if(j)
					temp += dp[i][j-1];
					
				dp[i][j] = temp % 10000;
				
			}
			
		}
		
		string ans = to_string(dp[target.size()-1][s.size()-1]);
		while(ans.size() < 4)
			ans = "0" + ans;
			
		cout << "Case #" << time+1 << ": " << ans << "\n";
		
	}
	
	return 0;
}
