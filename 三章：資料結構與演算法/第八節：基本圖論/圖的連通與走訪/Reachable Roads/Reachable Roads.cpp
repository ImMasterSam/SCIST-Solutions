#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<vector<int>> graph;
vector<bool> vis;

void dfs(int cur){
	
	for(int nxt : graph[cur]){
		
		if(!vis[nxt]){
			
			vis[nxt] = true;
			dfs(nxt);
			
		}
		
	}
	
}

int main(){ BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		int n, m;
		cin >> n >> m;
		
		graph.assign(n, vector<int>());
		vis.assign(n, false);
		
		for(int i=0;i<m;i++){
			
			int a, b;
			cin >> a >> b;
			
			graph[a].push_back(b);
			graph[b].push_back(a);
			
		}
		
		int c = 0;
		for(int i=0;i<n;i++){
			
			if(!vis[i]){
				
				dfs(i);
				c++;
				
			}
			
		}
		
		cout << c-1 << "\n";
		
	}
	
	return 0;
}
