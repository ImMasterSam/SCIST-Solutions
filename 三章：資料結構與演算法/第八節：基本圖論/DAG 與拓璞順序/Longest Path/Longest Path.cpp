#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int n, m;
vector<vector<int>> edge;

int topo(){
	
	queue<int> q;
	vector<int> ind(n+1, 0);
	vector<int> finish(n+1, -1);
	
	for(int i=1;i<=n;i++){
		
		for(int j : edge[i]){
			
			ind[j]++;
			
		}
		
	}
	
	for(int i=1;i<=n;i++){
		
		if(!ind[i]){
			
			q.push(i);
			
		}
		
	}
	
	int MAX = 0;
	
	while(!q.empty()){
		
		int t = q.front();
		q.pop();
		
		finish[t]++;
		MAX = max(MAX, finish[t]);
		
		for(int i : edge[t]){
			
			finish[i] = max(finish[i], finish[t]);
			
			if(!(--ind[i])){
				
				q.push(i);
				
			}
			
		}
		
	}
	
	return MAX;
	
}

int main(){ BOOST

	cin >> n >> m;
	
	edge.assign(n+1, vector<int>());
	
	while(m--){
		
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);
		
	}
	
	int ans = topo();
	cout << ans << "\n";
	
	return 0;
}
