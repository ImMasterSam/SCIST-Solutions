#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int n, m;
vector<vector<int>> edge;

void topo(){
	
	queue<int> q;
	vector<int> ind(n+1, 0);
	
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
	
	vector<int> ans;
	while(!q.empty()){
		
		int t = q.front();
		q.pop();
		
		ans.push_back(t);
		
		for(int i : edge[t]){
			
			if(!(--ind[i])){
				
				q.push(i);
				
			}
			
		}
		
	}
	
	cout << ans[0];
	for(int i=1;i<n;i++)
		cout << " " << ans[i];
	cout << "\n";
	
}

int main(){ BOOST

	while(cin >> n >> m, n){
		
		edge.assign(n+1, vector<int>());
		
		while(m--){
			
			int i, j;
			cin >> i >> j;
			
			edge[i].push_back(j);
			
		}
		
		topo();
		
	}
	
	return 0;
}
