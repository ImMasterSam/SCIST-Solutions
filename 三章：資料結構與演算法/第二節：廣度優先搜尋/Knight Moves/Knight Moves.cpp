#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

map<char, int> code = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4},
					   {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}};
					   
int jump[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
				  {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
				  
struct node{
	
	int x, y;
	int dis;
	
};
					   
queue<node> q;
bool used[10][10] = {0};

int bfs(int sx, int sy, int ex, int ey){
	
	node cur, nxt;
	memset(used, 0, sizeof(used));
	
	cur.x = sx;
	cur.y = sy;
	cur.dis = 0;
	
	q.push(cur);
	used[sx][sy] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.x == ex && cur.y == ey){
			
			return cur.dis;
			
		}
		
		for(int i=0;i<8;i++){
			
			nxt = cur;
			nxt.x += jump[i][0];
			nxt.y += jump[i][1];
			nxt.dis++;
			
			if((nxt.x>=1&&nxt.x<=8) && (nxt.y>=1&&nxt.y<=8)){
				
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
	
	string start;
	string end;
	
	while(cin >> start >> end){
		
		while(q.size()) q.pop();
		
		int sx, sy, ex, ey;
		sx = code[start[0]];
		sy = start[1] - '0';
		ex = code[end[0]];
		ey = end[1] - '0';
		
		int dis = bfs(sx, sy, ex, ey);
		
		cout << "To get from " << start << " to " << end << " takes " << dis << " knight moves.\n";
		
	}
	
	return 0;
}