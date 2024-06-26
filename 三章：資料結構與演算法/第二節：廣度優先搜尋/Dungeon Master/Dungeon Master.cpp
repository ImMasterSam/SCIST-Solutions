#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dir[6][3] = {{1, 0, 0}, {-1, 0, 0},
				 {0, 1, 0}, {0, -1, 0},
				 {0, 0, 1}, {0, 0, -1}};

struct node{
	
	int x, y, z;
	int dis;
	
};

int l, r, c;
queue<node> q;
char board[30][30][30] = {0};
bool used[30][30][30] = {0};

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(empty, q);
	
}

int bfs(int sx, int sy, int sz, int ex, int ey, int ez){
	
	node cur, nxt;
	memset(used, false, sizeof(used));
	clear(q);
	
	cur.x = sx;
	cur.y = sy;
	cur.z = sz;
	cur.dis = 0;
	
	q.push(cur);
	
	used[sx][sy][sz] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.x == ex && cur.y == ey && cur.z == ez){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<6;i++){
			
			 nxt = cur;
			 nxt.x += dir[i][0];
			 nxt.y += dir[i][1];
			 nxt.z += dir[i][2];
			 nxt.dis++;
			 
			 if((nxt.x>=0&&nxt.x<l) && (nxt.y>=0&&nxt.y<r) && (nxt.z>=0&&nxt.z<c)){
			 	
			 	if(board[nxt.x][nxt.y][nxt.z]!='#' && !used[nxt.x][nxt.y][nxt.z]){
			 		
			 		used[nxt.x][nxt.y][nxt.z] = true;
			 		q.push(nxt);
			 		
			 	}
			 	
			 }
			
		}
		
	}
	
	return -1;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(cin >> l >> r >> c){
		
		int sx, sy, sz;
		int ex, ey, ez;
		
		if(l==0 && r==0 && c==0)
			break;
			
		// input
		for(int i=0;i<l;i++){
			
			for(int j=0;j<r;j++){
				
				for(int k=0;k<c;k++){
					
					cin >> board[i][j][k];
					
					if(board[i][j][k] == 'S'){
						
						sx = i;sy = j;sz = k;
						
					}
					
					if(board[i][j][k] == 'E'){
						
						ex = i;ey = j;ez = k;
						
					}
					
				}
				
			}
			
		}
		
		int time = bfs(sx, sy, sz, ex, ey, ez);
		
		if(time == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << time << " minute(s).\n";
		
	}
	
	return 0;
}