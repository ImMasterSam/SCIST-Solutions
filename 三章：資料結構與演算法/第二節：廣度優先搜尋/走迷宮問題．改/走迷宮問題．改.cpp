#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <map>
using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
map<char, int> direction = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

int n, m, f;
char board[1024][1024];

struct node{
	
	int x, y;
	int face;
	int dis;
	
};

queue<node> q;
int used[1024][1024];

int bfs(int sx, int sy, int f, int ex, int ey){
	
	node cur, nxt;
	for(int i=0;i<1024;i++)
		for(int j=0;j<1024;j++)
			used[i][j] = INT_MAX;
	
	cur.x = sx;
	cur.y = sy;
	cur.face = f;
	cur.dis = 0;
	
	q.push(cur);
	
	used[sy][sx] = 0;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		for(int i=0;i<4;i++){
			
			int face = (cur.face+i)%4;
			
			nxt = cur;
			nxt.x += dir[face][0];
			nxt.y += dir[face][1];
			nxt.face = face;
			nxt.dis++;
			
			if(face != cur.face)
				nxt.dis += abs(face - cur.face);
						
			if((nxt.x>=0&&nxt.x<m) && ((nxt.y>=0&&nxt.y<n))){
				
				if(board[nxt.y][nxt.x] != '#' && nxt.dis < used[nxt.y][nxt.x]){
					
					used[nxt.y][nxt.x] = nxt.dis;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	
	return -1;
}

int main(){
	
	cin >> n >> m;
	
	char c;
	cin >> c;
	f = direction[c];
	
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
	
	bfs(sx, sy, f, ex, ey);
	
	cout << used[ey][ex];
	
	return 0;
}