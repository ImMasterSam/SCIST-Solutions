#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int w, h;
int ans = 0;
char board[50][50];
bool used[50][50];
bool dang[50][50];
queue<pair<int, int>> q;

void clear(queue<pair<int, int>> &q){
	
	queue<pair<int, int>> empty;
	swap(q, empty);
	
}

void bfs(int sx, int sy){
	
	pair<int, int> cur, nxt;
	
	cur.f = sx;
	cur.s = sy;
	
	q.push(cur);
	used[sx][sy] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(dang[cur.f][cur.s])
			continue;
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.f += dir[i][0];
			nxt.s += dir[i][1];
			
			if((nxt.f>=0 && nxt.f<h) && (nxt.s>=0 && nxt.s<w)){
				
				if(!used[nxt.f][nxt.s] && board[nxt.f][nxt.s] != 'T' && board[nxt.f][nxt.s] != '#'){
					
					if(board[nxt.f][nxt.s] == 'G'){
						
						ans++;
						
					}
					
					used[nxt.f][nxt.s] = true;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
}

int main(){
	
	while(cin >> w >> h){
		
		memset(used, false, sizeof(used));
		memset(dang, false, sizeof(dang));
		clear(q);
		
		int sx, sy;
		
		for(int i=0;i<h;i++){
			
			for(int j=0;j<w;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] == 'P'){
					
					sx = i;
					sy = j;
					
				}
				
				if(board[i][j] == 'T'){
					
					int x, y;
					
					for(int k=0;k<4;k++){
						
						x = i + dir[k][0];
						y = j + dir[k][1];
						
						if((x>=0 && x<h) && (y>=0 && y<w)){
							
							dang[x][y] = true;
							
						}
						
					}
					
				}
				
			}	
			
		}
		
		
		ans = 0;
		bfs(sx, sy);
		
		cout << ans << "\n";
		
	}
	
	return 0;
}