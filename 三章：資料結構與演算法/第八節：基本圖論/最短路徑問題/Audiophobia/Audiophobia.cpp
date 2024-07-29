#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int INF = 1e9;

struct edge{
	
	int target;
	int weight;
	
};

struct cmp{
	
	bool operator () (const edge &a, const edge &b){
		
		return a.weight > b.weight;
		
	}
	
};

int c, s, q;
vector<vector<edge>> graph;
vector<int> dis;

int dijkstra(int start, int end){
	
	dis.assign(c+1, INF);
	
	edge cur;
	edge nxt;
	
	priority_queue<edge, vector<edge>, cmp> pq;
	
	cur.target = start;
	cur.weight = 0;
	dis[start] = 0;
	
	pq.push(cur);
	
	while(pq.size()){
		
		cur = pq.top();
		pq.pop();
		
		int pos = cur.target;
		int dB = cur.weight;
		
		if(pos == end){
			
			return dB;
			
		}
		
		if(dB == dis[pos]){
			
			for(int i=0;i<graph[pos].size();i++){
				
				nxt = graph[pos][i];
				
				if(max(dB, nxt.weight) < dis[nxt.target]){
					
					dis[nxt.target] = max(dB, nxt.weight);
					
					nxt.weight = max(dB, nxt.weight);
					pq.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	return -1;
	
}

int main(){ BOOST

	int time = 1;
	bool first = true;

	while(cin >> c >> s >> q, c){
		
		graph.assign(c+1, vector<edge>());
		dis.assign(c+1, INF);
		
		for(int i=0;i<s;i++){
			
			int c1, c2, d;
			cin >> c1 >> c2 >> d;
			
			edge temp;
			temp.weight = d;
			
			temp.target = c2;
			graph[c1].push_back(temp);
			
			temp.target = c1;
			graph[c2].push_back(temp);
			
		}
		
		if(!first)
			cout << "\n";
		
		cout << "Case #" << time++ << "\n";
		
		while(q--){
			
			int c1, c2;
			cin >> c1 >> c2;
			
			int res = dijkstra(c1, c2);
			
			if(res == -1)
				cout << "no path\n";
			else
				cout << res << "\n";
			
		}
		
		first = false;
		
	}
	
	return 0;
}
