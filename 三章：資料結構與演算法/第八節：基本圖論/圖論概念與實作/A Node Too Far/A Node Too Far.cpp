#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	int pos;
	int ttl;
	
};

int n, vis_count = 0, t = 1;
map<int, vector<int>> graph;
map<int, bool> vis;

void bfs(int start, int ttl){
	
	node cur;
	node nxt;
	
	cur.pos = start;
	cur.ttl = ttl;
	vis[start] = true;
	vis_count++;
	
	queue<node> q;
	q.push(cur);
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.ttl == 0)
			continue;
		
		for(int nxt_pos : graph[cur.pos]){
			
			nxt.pos = nxt_pos;
			nxt.ttl = cur.ttl - 1;
			
			if(graph.find(nxt.pos) != graph.end() && !vis[nxt.pos]){
				
				vis[nxt.pos] = true;
				vis_count++;
				q.push(nxt);
				
			}
			
		}
		
	}
	
}

int main(){ BOOST

	while(cin >> n, n){
		
		decltype(graph)().swap(graph);
		
		int a, b;
		
		for(int i=0;i<n;i++){
			
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			
		}
		
		while(cin >> a >> b){
			
			if(a == 0 && b == 0)
				break;
				
			decltype(vis)().swap(vis);
			vis_count = 0;
			
			if(graph.find(a) != graph.end()){
				
				bfs(a, b);
				
			}
			
			
			cout << "Case " << t++ << ": ";
			cout << graph.size() - vis_count;
			cout << " nodes not reachable from node " << a;
			cout << " with TTL = " << b << ".\n";
			
		}
		
	}
	
	return 0;
}
