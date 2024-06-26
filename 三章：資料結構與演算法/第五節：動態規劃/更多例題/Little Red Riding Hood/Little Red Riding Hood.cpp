#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int w, h;
int dp[101][101];
bool block[101][101];

int main(){ BOOST
	
	while(cin >> w >> h){
		
		if(w == 0 && h == 0)
			break;
			
		memset(dp, 0, sizeof dp);
		memset(block, false, sizeof block);
		
		int n;
		cin >> n;
		
		for(int i=0, x, y;i<n;i++){
			
			cin >> x >> y;
			block[x][y] = true;
			
		}
		
		for(int i=0;i<=w;i++){
			
			for(int j=0;j<=h;j++){
				
				if(i == 0 && j == 0)
					dp[i][j] = 1;
					
				else{
					
					if(i && !block[i-1][j])
						dp[i][j] += dp[i-1][j];
					if(j && !block[i][j-1])
						dp[i][j] += dp[i][j-1]; 
					
				}
				
			}
			
		}
		
		switch(dp[w][h]){
			
			case 0:
				cout << "There is no path.\n";
				break;
			case 1:
				cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
				break;
			default:
				cout << "There are " << dp[w][h] << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
				break;
			
		}
		
	}
	
	return 0;
}
