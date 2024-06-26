#include <bits/stdc++.h>
using namespace std;

int dp[100] = {0};
int money[100][100];

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int c, s, e, t;
	
	while(cin >> c >> s >> e >> t){
		
		memset(dp, 0, sizeof dp);
		
		if(c==0 && s==0 && e==0 && t==0)
			break;
			
		//cout << c << " " << s << " " << e << " " << t << "\n";
		
		for(int i=0;i<c;i++){
			
			for(int j=0;j<c;j++){
				
				cin >> money[i][j];
				
			}
			
		}
		
		int ends[e];
		
		for(int i=0;i<e;i++)
			cin >> ends[i];
		
		int T[100] = {0};
		int *a = dp;
		int *b = T;
		
		for(int i=0;i<c;i++){
			
			if(i == s-1) continue;
			
			a[i] = money[s-1][i];
			
		}
		
		for(int time=1;time<t;time++){
			
			swap(a, b);
			
			for(int i=0;i<c;i++){
				
				int temp = 0;
				
				for(int j=0;j<c;j++){
					
					if(j == i || b[j] == 0) continue;
					
					temp = max(temp, b[j]+money[j][i]);
					
				}
				
				a[i] = temp;
				
			}
			
		}
		
		if(t == 0){
			
			cout << 0 << "\n";
			
		}
		else{
			
			int ans = 0;
			
			for(int i=0;i<e;i++){
				
				ans = max(ans, a[ends[i]-1]);
				
			}
			
			cout << ans << "\n";
			
		}
		
	}
		
	return 0;
}