#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct edge{
	
	int target;
	int weight;
	
};

const int INF = 1e9;
using ve = vector<edge>;

int n, m, s, t;
vector<ve> graph;
vector<int> dis;

bool relax(){
	
	bool updated = false;
	
	for(int i=0;i<n;i++){
		
		if(dis[i] == INF)
			continue;
			
		for(int j=0;j<graph[i].size();j++){
			
			edge e = graph[i][j];
			
			if(dis[i] + e.weight < dis[e.target]){
				
				dis[e.target] = dis[i] + e.weight;
				updated =  true;
				
			}
			
		}
		
	}
	
	return updated;
	
}

void bellman_ford(int start){
	
	dis.assign(n, INF);
	
	dis[start] = 0;
	
	for(int i=1;i<n;i++){
		
		if(!relax()){
			
			break;
			
		}
		
	}
	
}

int main(){ BOOST

	int tc;
	cin >> tc;
	
	for(int time=1;time<=tc;time++){
		
		cin >> n >> m >> s >> t;
		
		graph.assign(n, ve());
		dis.assign(n, INF);
		
		for(int i=0;i<m;i++){
			
			int u, v, w;
			cin >> u >> v >> w;
			
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
			
		}
		
		cout << "Case #" << time << ": ";
		
		bellman_ford(s);
		
		if(dis[t] == INF)
			cout << "unreachable\n";
		else
			cout << dis[t] << "\n";
		
	}
	
	return 0;
}
