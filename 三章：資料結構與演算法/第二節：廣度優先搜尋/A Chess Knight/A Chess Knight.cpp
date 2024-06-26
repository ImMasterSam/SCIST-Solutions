#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int k[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
			   {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
			   
int b[4][2] = {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}};

struct node{
	
	int x, y;
	int dis;
	char last;
	
};

int n;
bool block[61][61] = {0};
int vis[61][61] = {0};
queue<node> q;
/*
void draw(){
	
	for(int i=1;i<=2*n;i++){
		
		for(int j=1;j<=2*n;j++){
			
			if(block[i][j])
				cout << "# ";
			
			else if(vis[i][j] == INT_MAX)
				cout << "X ";
			
			else
				cout << vis[i][j] << " ";
			
		}
		
		cout << "\n";
		
	}
	
	cout << "\n";
	
}
*/
void clear(queue<node> &q){
	
	queue<node> empty;
	swap(q, empty);
	
}

void bfs(int sx, int sy){
	
	node cur, nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	cur.last = '#';
	
	q.push(cur);
	vis[sx][sy] = 0;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		//draw();
		
		if(cur.last != 'K'){
			
			for(int i=0;i<8;i++){
				
				nxt = cur;
				nxt.x += k[i][0];
				nxt.y += k[i][1];
				nxt.dis++;
				nxt.last = 'K';
				
				if((nxt.x>=1&&nxt.x<=2*n) && (nxt.y>=1&&nxt.y<=2*n)){
					
					if(!block[nxt.x][nxt.y] && nxt.dis <= vis[nxt.x][nxt.y]){
						
						vis[nxt.x][nxt.y] = nxt.dis;
						q.push(nxt);
						
					}
					
				}
								
				
			}
			
		}
		
		if(cur.last != 'B'){
			
			for(int i=0;i<4;i++){
				
				nxt = cur;
				nxt.x += b[i][0];
				nxt.y += b[i][1];
				nxt.dis++;
				nxt.last = 'B';
				
				if((nxt.x>=1&&nxt.x<=2*n) && (nxt.y>=1&&nxt.y<=2*n)){
					
					if(!block[nxt.x][nxt.y] && nxt.dis <= vis[nxt.x][nxt.y]){
						
						vis[nxt.x][nxt.y] = nxt.dis;
						q.push(nxt);
						
					}
					
				}
								
				
			}
			
		}
		
		if(cur.last != 'T'){
			
			for(int i=0;i<2;i++){
				
				nxt = cur;
				nxt.dis++;
				nxt.last = 'T';
				
				if(i == 0){
					
					nxt.x = 2*n - nxt.x + 1;
					
				}
				if(i == 1){
					
					nxt.y = 2*n - nxt.y + 1;
					
				}
				
				if((nxt.x>=1&&nxt.x<=2*n) && (nxt.y>=1&&nxt.y<=2*n)){
					
					if(!block[nxt.x][nxt.y] && nxt.dis <= vis[nxt.x][nxt.y]){
						
						vis[nxt.x][nxt.y] = nxt.dis;
						q.push(nxt);
						
					}
					
				}
								
				
			}
			
		}
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(cin >> n, n){
		
		memset(block, false, sizeof(block));
		clear(q);
		
		int sx, sy, ex, ey;
		cin >> sx >> sy;
		cin >> ex >> ey;
		
		int x, y;
		
		while(cin >> x >> y){
			
			if(x == 0 && y == 0)
				break;
				
			block[x][y] = true;
			
		}
		
		for(int i=1;i<=2*n;i++){
			
			for(int j=1;j<=2*n;j++)
				vis[i][j] = INT_MAX;
			
		}
		
		bfs(sx, sy);
		
		if(vis[ex][ey] == INT_MAX)
			cout << "Solution doesn't exist\n";
		else
			cout << "Result : " << vis[ex][ey] << "\n";
		
	}
	
	return 0;
}