#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct node{
	
	int x, y;
	int dis;
	
};

int r, c;
char board[1000][1000];
vector<vector<int>> step (1000, vector<int>(1000, INT_MAX));
queue<pair<int, int>> fires;
queue<node> q;

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(q, empty);
	
}

void bfs_fire(int sx, int sy){
	
	node cur;
	node nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	step[sx][sy] = 0;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if((nxt.x>=0 && nxt.x<r) && (nxt.y>=0 && nxt.y<c)){
				
				if(board[nxt.x][nxt.y] != '#' && board[nxt.x][nxt.y] != 'J'){
					
					if(nxt.dis < step[nxt.x][nxt.y]){
						
						step[nxt.x][nxt.y] = nxt.dis;
						q.push(nxt);
						
					}
					
				}
				
			}
			
		}
		
	}
	
}

int  bfs_joe(int sx, int sy){
	
	node cur;
	node nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	step[sx][sy] = 0;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if(nxt.x<0 || nxt.x>=r || nxt.y<0 || nxt.y>=c){
				
				return nxt.dis;
				
			}
			
			if((nxt.x>=0 && nxt.x<r) && (nxt.y>=0 && nxt.y<c)){
				
				if(board[nxt.x][nxt.y] != '#' && board[nxt.x][nxt.y] != 'J'){
					
					if(nxt.dis < step[nxt.x][nxt.y]){
						
						step[nxt.x][nxt.y] = nxt.dis;
						q.push(nxt);
						
					}
					
				}
				
			}
			
		}
		
	}
	
	return -1;
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		step.assign(1000, vector<int>(1000, INT_MAX));
		clear(q);
		
		cin >> r >> c;
		
		int sx, sy, fx, fy;
		
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] == 'J'){
					
					sx = i;
					sy = j;
					
				}
				
				if(board[i][j] == 'F'){
					
					fires.push(make_pair(i, j));
					
				}
				
			}
			
		}
		
		while(fires.size()){
			
			bfs_fire(fires.front().f, fires.front().s);
			fires.pop();
			clear(q);
			
		}
		
		int res = bfs_joe(sx, sy);
		
		if(res == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
		
		
	}
	
	return 0;
}