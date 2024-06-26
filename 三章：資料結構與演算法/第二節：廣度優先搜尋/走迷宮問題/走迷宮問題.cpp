#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int n, m;
char board[1024][1024];

struct node{
	
	int x, y;
	int dis;
	
};

queue<node> q;
bool used[1024][1024] = {0};

int bfs(int sx, int sy, int ex, int ey){
	
	node cur, nxt;
	memset(used, 0, sizeof(used));
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	
	used[sy][sx] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.x == ex && cur.y == ey){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if((nxt.x>=0&&nxt.x<m) && ((nxt.y>=0&&nxt.y<n))){
				
				if(board[nxt.y][nxt.x] != '#' && !used[nxt.y][nxt.x]){
					
					used[nxt.y][nxt.x] = true;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	
	return -1;
}

int main(){
	
	cin >> n >> m;
	
	int sx, sy, ex, ey;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin >> board[i][j];
			
			if(board[i][j] == 'S'){
				
				sx = j;
				sy = i;
				
			}
			if(board[i][j] == 'E'){
				
				ex = j;
				ey = i;
				
			}
			
		}
		
	}
	
	cout << bfs(sx, sy, ex, ey);
	
	
	return 0;
}