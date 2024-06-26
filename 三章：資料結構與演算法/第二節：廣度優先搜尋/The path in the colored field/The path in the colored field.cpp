#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define f first
#define s second

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct node{
	
	int x, y;
	int dis;
	
};

int n;
char board[100][100];
int used[100][100] = {0};

queue<node> q;
queue<pair<int, int>> ones;

void clear(queue<node> &q){
	
	queue<node> empty;
	swap(empty, q);
	
}

int bfs(int sx, int sy){
	
	node cur, nxt;
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(board[cur.x][cur.y] == '3'){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			nxt.dis++;
			
			if((nxt.x>=0&&nxt.x<n) && (nxt.y>=0&&nxt.y<n)){
				
				if(!used[nxt.x][nxt.y]){
					
					used[nxt.x][nxt.y] = true;
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
	
	while(cin >> n){
		
		int MAX = 0;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] == '1')
					ones.push(make_pair(i, j));
				
			}
			
		}
		
		pair<int, int> temp;
		
		while(ones.size()){
			
			memset(used, false, sizeof(used));
			clear(q);
			temp = ones.front(), ones.pop();
			
			int dis = bfs(temp.f, temp.s);
			
			if(dis > MAX){
				
				MAX = dis;
				
			}
			
		}
		
		cout << MAX << "\n";
		
	}
	
	
	return 0;
}