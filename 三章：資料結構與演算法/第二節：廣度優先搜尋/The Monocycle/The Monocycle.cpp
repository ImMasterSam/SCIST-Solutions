#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct node{
	
	int x, y;
	int dis;
	int face;
	int color;
	
};

int m, n;
char board[26][26];
bool used[26][26][4][5] = {0};
queue<node> q;

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(q, empty);
	
}

int bfs(int sx, int sy, int ex, int ey){
	
	node cur, nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	cur.face = 0;
	cur.color = 0;
	
	q.push(cur);
	used[sx][sy][0][0] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.x == ex && cur.y == ey && cur.color == 0){
			
			return cur.dis;
			
		}
		
		//straight
		nxt = cur;
		nxt.x += dir[nxt.face][0];
		nxt.y += dir[nxt.face][1];
		nxt.dis++;
		nxt.color = (nxt.color+1)%5;
		
		if((nxt.x>=0&&nxt.x<m) && (nxt.y>=0&&nxt.y<n) && board[nxt.x][nxt.y] != '#'){
			
			if(!used[nxt.x][nxt.y][nxt.face][nxt.color]){
				
				used[nxt.x][nxt.y][nxt.face][nxt.color] = true;
				q.push(nxt);
				
			}
			
		}
		
		//right
		nxt = cur;
		nxt.face = (nxt.face+1)%4;
		nxt.dis++;
		
		if((nxt.x>=0&&nxt.x<m) && (nxt.y>=0&&nxt.y<n) && board[nxt.x][nxt.y] != '#'){
			
			if(!used[nxt.x][nxt.y][nxt.face][nxt.color]){
				
				used[nxt.x][nxt.y][nxt.face][nxt.color] = true;
				q.push(nxt);
				
			}
			
		}
		
		//left
		nxt = cur;
		nxt.face = (nxt.face+3)%4;
		nxt.dis++;
		
		if((nxt.x>=0&&nxt.x<m) && (nxt.y>=0&&nxt.y<n) && board[nxt.x][nxt.y] != '#'){
			
			if(!used[nxt.x][nxt.y][nxt.face][nxt.color]){
				
				used[nxt.x][nxt.y][nxt.face][nxt.color] = true;
				q.push(nxt);
				
			}
			
		}
		
	}
	
	return -1;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bool first = true;
	int time = 1;
	
	while(cin >> m >> n){
		
		if(m==0 && n==0)
			break;
		
		memset(used, false, sizeof(used));
		clear(q);
		
		int sx, sy, ex, ey;
		
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] == 'S'){
					
					sx = i;
					sy = j;
					
				}
				
				if(board[i][j] == 'T'){
					
					ex = i;
					ey = j;
					
				}
				
			}
			
		}
		
		int dis = bfs(sx, sy, ex, ey);
		
		if(!first)
			cout << "\n";
			
		cout << "Case #" << time++ << "\n";
		
		if(dis == -1)
			cout << "destination not reachable\n";
		else
			cout << "minimum time = " << dis << " sec\n";
			
		first = false;
		
	}
	
	return 0;
}