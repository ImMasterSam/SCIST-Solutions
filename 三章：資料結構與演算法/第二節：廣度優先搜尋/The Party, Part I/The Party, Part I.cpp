#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define f first
#define s second

int p, d;
bool side[1001][1001] = {0};
bool used[1001] = {0};
int num[1001] = {0};
queue<pair<int, int>> q;

void clear(queue<pair<int, int>> &q){
	
	queue<pair<int, int>> empty;
	swap(empty, q);
	
}

void bfs(){
	
	pair<int, int> cur, nxt;
	
	cur.f = 0;
	cur.s = 0;
	
	q.push(cur);
	used[cur.f] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		//cout << "idx: " << cur.f << "\n";
		
		for(int i=1;i<p;i++){
			
			nxt = cur;
			nxt.f = i;
			nxt.s++;
			
			if(side[cur.f][i] && !used[i]){
				
				used[i] = true;
				q.push(nxt);
				
			}
			
		}
		
		num[cur.f] = cur.s;
		
	}
	
}

int main(){
	
	int n;
	cin >> n;
	
	bool first = true;
	
	while(n--){
		
		memset(used, false, sizeof(used));
		memset(side, false, sizeof(side));
		clear(q);
		
		cin >> p >> d;
		
		for(int i=0, a, b;i<d;i++){
			
			cin >> a >> b;
			side[a][b] = side[b][a] = true;
			
		}
		
		bfs();
		
		if(!first)
			cout << "\n";
		
		for(int i=1;i<p;i++){
			
			cout << num[i] << "\n";
			
		}
		
		first = false;
		
	}
	
	
	
	return 0;
}