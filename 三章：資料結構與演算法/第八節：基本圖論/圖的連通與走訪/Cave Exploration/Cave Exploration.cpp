#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

long long h[105][105] = {0};
bool vis[105][105] = {0};
using pp = pair<int, int>;

#define f first
#define s second

struct cmp{
	
	bool operator () (const pp &a, const pp &b){
		
		return h[a.f][a.s] > h[b.f][b.s];
		
	}
	
};

int main(){ BOOST

	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++)
			cin >> h[i][j];
		
	}
	
	priority_queue<pp, vector<pp>, cmp> pq;
	
	long long MAX = 0;
	pp cur = {0, 0};
	pp nxt;
	
	vis[0][0] = true;
	pq.push(cur);
	
	// Dijkstra
	while(pq.size()){
		
		cur = pq.top();
		pq.pop();
		
		MAX = max(MAX, h[cur.f][cur.s]);
		
		if(cur.f == n-1 && cur.s == n-1)
			break;
		
		for(int i=0;i<4;i++){
			
			nxt = cur;
			nxt.f += dir[i][0];
			nxt.s += dir[i][1];
			
			if(nxt.f>=0 && nxt.f<n && nxt.s>=0 && nxt.s<n){
				
				if(!vis[nxt.f][nxt.s]){
					
					vis[nxt.f][nxt.s] = true;
					pq.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	cout << MAX << "\n";
	
	return 0;
}
