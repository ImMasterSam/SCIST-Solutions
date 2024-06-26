#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
int dp[1000][1000];
int board[1000][1000];

int main(){
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			char c;
			cin >> c;
			
			board[i][j] = c - '0';
			dp[i][j] = 0;
			
			if(c == '9')
				dp[i][j]++;
			
		}
		
	}
	
	for(int time=0;time<9;time++){
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<m;j++){
				
				if(board[i][j] == 9)
					continue;
				
				int temp = 0;
				
				for(int d=0;d<4;d++){
					
					int x = i + dir[d][0];
					int y = j + dir[d][1];
					
					if((x>=0&&x<n) && (y>=0&&y<m)){
						
						if(board[x][y] == board[i][j]+1)
							temp += dp[x][y];
						
					}
					
				}
				
				dp[i][j] = temp;
				
			}
			
		}
		
	}
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			//cout << dp[i][j] << " ";
			
			if(board[i][j] == 0)
				ans += dp[i][j];
			
		}
		
		//cout << "\n";
		
	}
	
	cout << ans << "\n";
	
	return 0;
}