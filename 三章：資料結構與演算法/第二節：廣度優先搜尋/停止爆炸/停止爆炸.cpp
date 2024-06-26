#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
int board[1001][1001];
bool used[1001][1001];
queue<pair<int, int>> q;

void clear(queue<pair<int, int>> &q){
	
	queue<pair<int, int>> empty;
	swap(q, empty);
	
}

bool bfs(int sx, int sy, int ex, int ey){
	
	memset(used, false, sizeof(used));
	clear(q);
	pair<int, int> cur, nxt;
	
	cur.f = sx;
	cur.s = sy;
	
	q.push(cur);
	used[sx][sy] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(abs(cur.f - ex) + abs(cur.s - ey) <= 3){
			
			return true;
			
		}
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.f += dir[i][0];
			nxt.s += dir[i][1];
			
			if((nxt.f>=1 && nxt.f<=n) && (nxt.s>=1 && nxt.s<=m)){
				
				if(board[nxt.f][nxt.s] - board[cur.f][cur.s] <= 1 && board[cur.f][cur.s] - board[nxt.f][nxt.s] <= 2){
					
					if(!used[nxt.f][nxt.s]){
						
						used[nxt.f][nxt.s] = true;
						q.push(nxt);
						
					}
					
				}
				
			}
			
		}
		
	}
	
	return false;
	
}

int main(){
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++)
			cin >> board[i][j];
		
	}
	
	int sx, sy, ex, ey;
	
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	cout << (bfs(sx, sy, ex, ey) ? "yes\n" : "no\n");
	
	
	return 0;
}