#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	int pos;
	int dis;
	
};

struct cmp{
	
	bool operator () (const node &a, const node &b){
		
		return a.dis > b.dis;
		
	}
	
};

int main(){ BOOST

	int n, s, t;
	cin >> n >> s >> t;
	
	int edge[n][n];
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++)
			cin >> edge[i][j];
		
	}
	
	vector<int> dis(n, INT_MAX);
	priority_queue<node, vector<node>, cmp> pq;
	
	node cur;
	node nxt;
	
	cur.pos = s;
	cur.dis = 0;
	dis[s] = 0;
	
	pq.push(cur);
	
	while(pq.size()){
		
		cur = pq.top();
		pq.pop();
		
		if(cur.dis == dis[cur.pos]){
			
			for(int i=0;i<n;i++){
				
				nxt = cur;
				nxt.pos = i;
				nxt.dis += edge[cur.pos][i];
				
				if(nxt.dis < dis[i]){
					
					dis[i] = nxt.dis;
					pq.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	cout << dis[t] << "\n";
	
	return 0;
}
