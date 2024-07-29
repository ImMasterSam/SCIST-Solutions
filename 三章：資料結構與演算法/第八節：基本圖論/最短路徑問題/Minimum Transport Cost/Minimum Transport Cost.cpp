#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int t, n, x;
stringstream ss;
vector<vector<int>> graph;
vector<int> ticket;

vector<int> dis;
vector<int> pre;

struct edge{
	
	int dis;
	int target;
	
};

struct cmp{
	
	bool operator () (const edge &a, const edge &b){
		
		return a.dis > b.dis;
		
	}
	
};

int main(){ BOOST

	bool first = true;

	cin >> t;
	cin.ignore(2);
	
	while(t--){
		
		graph.assign(1, vector<int>());
		
		// Input
		
		string buffer;
		getline(cin, buffer);
		
		ss.str();
		ss.clear();
		
		ss << buffer;
		while(ss >> x){
			
			graph[0].push_back(x);
			
		}
		
		n = graph[0].size();
		graph.resize(n, vector<int>());
		ticket.assign(n, 0);
		for(int i=1;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> x;
				graph[i].push_back(x);
				
			}
		}
		
		for(int i=0;i<n;i++)
			cin >> ticket[i];
		/*
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++)
				cout << graph[i][j] << " ";
			cout << "\n";
			
		}
		*/
		// Search
		int a, b;
		cin.ignore();
		while(getline(cin, buffer), buffer != ""){
			
			sscanf(buffer.c_str(), "%d %d", &a, &b);
			
			pre.assign(n, -1);
			dis.assign(n, INT_MAX);
			priority_queue<edge, vector<edge>, cmp> pq;
			
			edge cur;
			edge nxt;
			
			cur.dis = 0;
			cur.target = a-1;
			pq.push(cur);
			
			dis[a-1] = 0;
			pre[a-1] = -1;
			
			while(pq.size()){
				
				cur = pq.top();
				pq.pop();
				
				if(cur.target == b-1)
					break;
					
				int distance = cur.dis;
				int pos = cur.target;
					
				if(dis[pos] == distance){
					
					for(int i=0;i<n;i++){
						
						if(i == pos || graph[pos][i] == -1) continue;
						
						nxt = cur;
						nxt.dis += graph[pos][i] + ticket[i];
						nxt.target = i;
						
						if(nxt.dis < dis[i]){
							
							dis[i] = nxt.dis;
							pq.push(nxt);
							
							pre[i] = pos;
							
						}
						
					}
					
				}
				
			}
			
			vector<int> path;
			
			int travel_pos = b-1;
			while(travel_pos != -1){
				
				path.push_back(travel_pos + 1);
				travel_pos = pre[travel_pos];
				
			}
			
			if(!first)
				cout << "\n";
			
			cout << "From " << a << " to " << b << " :\n";
			
			cout << "Path: ";
			cout << path[path.size()-1];
			for(int i=path.size()-2;i>=0;i--)
				cout << "-->" << path[i];
			cout << "\n";
			
			int ans = dis[b-1];
			if(ans != 0)
				ans -= ticket[b-1];
			
			cout << "Total cost : " << ans << "\n";
			
			first = false;
			
		}
		
	}
	
	return 0;
}
