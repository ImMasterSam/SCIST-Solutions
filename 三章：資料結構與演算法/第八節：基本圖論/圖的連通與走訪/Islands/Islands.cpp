#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int r, c;
char board[51][51] = {0};
bool vis[51][51] = {0};

void dfs(int row, int col){
	
	for(int i=0;i<4;i++){
		
		int x = row + dir[i][0];
		int y = col + dir[i][1];
		
		if(x>=0 && x<r && y>=0 && y<c){
			
			if(!vis[x][y] && board[x][y] != 'W'){
				
				vis[x][y] = true;
				dfs(x, y);
				
			}
			
		}
		
	}
	
}

int main(){ BOOST

	cin >> r >> c;
	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++)
			cin >> board[i][j];
		
	}
	
	int cnt = 0;
	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++){
			
			if(!vis[i][j] && board[i][j] == 'L'){
				
				vis[i][j] = true;
				dfs(i, j);
				cnt++;
				
			}
			
		}
		
	}
	
	cout << cnt << "\n";
	
	return 0;
}
