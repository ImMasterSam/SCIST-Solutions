#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

map<char, int> key = {{'r', 1}, {'g', 2}, {'b', 4}, {'y', 8}};
map<char, int> door = {{'R', 1}, {'G', 2}, {'B', 4}, {'Y', 8}};

struct node{
	
	int x, y;
	int key;
	int dis;
	
};

int r, c;
char board[100][100];
bool used[100][100][9];
queue<node> q;

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(q, empty);
	
}

int bfs(int sx, int sy){
	
	node cur;
	node nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	cur.key = 0;
	
	q.push(cur);
	used[sx][sy][0] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		//cout << cur.x << " : " << cur.y << ", K: " << cur.key << "\n";
		
		if(board[cur.x][cur.y] == 'X'){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if(islower(board[nxt.x][nxt.y])){
				
				nxt.key |= key[board[nxt.x][nxt.y]];
				
			}
			
			if((nxt.x>=0 && nxt.x<r) && (nxt.y>=0 && nxt.y<c)){
				
				if(board[nxt.x][nxt.y]!='#' && !used[nxt.x][nxt.y][nxt.key]){
					
					if(isupper(board[nxt.x][nxt.y])){
						
						if(board[nxt.x][nxt.y] == 'X' || (nxt.key & door[board[nxt.x][nxt.y]])){
							
							used[nxt.x][nxt.y][nxt.key] = true;
							q.push(nxt);
							
						}
						
					}
					else{
						
						used[nxt.x][nxt.y][nxt.key] = true;
						q.push(nxt);
						
					}
					
				}
				
			}
			
		}
		
	}
	
	return -1;
}

int main(){
	
	while(cin >> r >> c){
		
		memset(used, false, sizeof(used));
		clear(q);
		
		int sx, sy;
		
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] == '*'){
					
					sx = i;
					sy = j;
					
				}
				
			}
			
		}
		
		int res = bfs(sx, sy);
		
		if(res == -1)
			cout << "The poor student is trapped!\n";
			
		else
			cout << "Escape possible in " << res << " steps.\n";
		
	}
	
	return 0;
}