#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int jump[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
				  {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
				  
int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
				 {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
				  
struct node{
	
	int x, y;
	int dis;
	
};

int n, m;
bool block[100][100] = {0};
bool used[100][100] = {0};
queue<node> q;

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(empty, q);
	
}

int bfs(int sx, int sy, int ex, int ey){
	
	node cur, nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	used[sx][sy] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		//cout << cur.x << " : " << cur.y << "\n";
		
		if(cur.x == ex && cur.y == ey){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<8;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if((nxt.x>=0&&nxt.x<n) && (nxt.y>=0&&nxt.y<m)){
				
				if(!block[nxt.x][nxt.y] && !used[nxt.x][nxt.y]){
					
					used[nxt.x][nxt.y] = true;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	return -1;
	
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		memset(block, false, sizeof(block));
		memset(used, false, sizeof(used));
		clear(q);
		
		int sx, sy, ex, ey;
		cin >> n >> m;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<m;j++){
				
				char c;
				cin >> c;
				
				if(c == 'A'){
					
					sx = i;
					sy = j;
					
				}
				if(c == 'B'){
					
					ex = i;
					ey = j;
					
				}
				if(c == 'Z'){
					
					block[i][j] = true;
					
					for(int k=0;k<8;k++){
						
						int x = i + jump[k][0];
						int y = j + jump[k][1];
						
						if((x>=0&&x<n) && (y>=0&&y<m))
							block[x][y] = true;
						
					}
					
				}
				
			}
			
		}
		
		block[ex][ey] = false;
		
		int dis = bfs(sx, sy, ex, ey);
		
		if(dis == -1)
			cout << "King Peter, you can't go now!\n";
		else
			cout << "Minimal possible length of a trip is " << dis << "\n";
		
	}
	
	return 0;
}