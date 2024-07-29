#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int INF = 1e9;

struct edge{
	
	int target;
	int weight;
	
};

int n, m;
vector<vector<edge>> graph;
vector<int> dis;

bool relax(){
	
	int updated = false;
	
	for(int i=0;i<n;i++){
		
		if(dis[i] == INF)
			continue;
		
		for(int j=0;j<graph[i].size();j++){
			
			edge e = graph[i][j];
			
			if(dis[i] + e.weight < dis[e.target]){
				
				dis[e.target] = dis[i] + e.weight;
				updated = true;
				
			}
			
		}
		
	}
	
	return updated;
	
}

bool bellman_ford(int start){
	
	dis.assign(n, INF);
	
	dis[start] = 0;
	
	for(int i=1;i<n;i++){
		
		if(!relax()){
			
			break;
			
		}
		
	}
	
	return relax();
	
}

int main(){ BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		cin >> n >> m;
		
		graph.assign(n, vector<edge>());
		
		for(int i=0;i<m;i++){
			
			int s, e, l;
			cin >> s >> e >> l;
			
			edge temp;
			temp.target = e;
			temp.weight = l;
			
			graph[s].push_back(temp);
			
		}
		
		cout << (bellman_ford(0) ? "possible" : "not possible") << "\n";
		
	}
	
	return 0;
}
