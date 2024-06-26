#include <iostream>
#include <queue>
using namespace std;

#define f first
#define s second

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m;
queue<pair<int, int>> q;
bool used[1005][1005] = {0};
bool fire[1005][1005] = {0};

bool bfs(int sx, int sy, int ex, int ey){
	
	pair<int, int> cur, nxt;
	
	cur.f = sx;
	cur.s = sy;
	
	q.push(cur);
	
	used[sx][sy] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.f == ex && cur.s == ey){
			
			return true;
			
		}
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.f += dir[i][0];
			nxt.s += dir[i][1];
			
			if((nxt.f>=1&&nxt.f<=n) && (nxt.s>=1&&nxt.s<=m)){
				
				if(!used[nxt.f][nxt.s] && !fire[nxt.f][nxt.s]){
					
					used[nxt.f][nxt.s] = true;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	
	return false;
}

int main(){
	
	cin >> n >> m;
	
	int sx, sy, ex, ey;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	int f;
	cin >> f;
	
	for(int i=0;i<f;i++){
		
		int u, v;
		cin >> u >> v;
		
		fire[u][v] = true;
		
	}
	
	cout << (bfs(sx, sy, ex, ey) ? "Cool!\n": "Harakiri!\n");
	
	return 0;
}