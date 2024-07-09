#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

char m, t;
int k;
vector<vector<int>> graph(26);
bool candle[26] = {false};
vector<char> path;
bool found = false;

void dfs(int m, int t, int depth){
	
	//cout << (char)(m + 'A') << ", " << (char)(t + 'A') << "\n";
	
	if(found)
		return;
		
	if(depth%k == 0){
		
		candle[m] = true;
		path.push_back(m + 'A');
		
	}
	
	bool wayout = false;
	for(int i=0;i<graph[m].size();i++){
		
		if(graph[m][i] != t && !candle[graph[m][i]]){
			
			dfs(graph[m][i], m, depth+1);
			wayout = true;
			
		}
		
	}
	
	if(!wayout){
		
		if(depth%k == 0)
			path.pop_back();
		
		for(int i=0;i<path.size();i++)
			cout << path[i] << " ";
		cout << "/" << (char)(m + 'A') << "\n";
		found = true;
	}
	
}

int main(){ BOOST

	string buffer;
	while(cin >> buffer){
		
		if(buffer == "#") break;
		cin >> m >> t >> k;
		
		// reset
		graph.assign(26, vector<int>(0));
		path.clear();
		memset(candle, false, sizeof candle);
		found = false;
		
		char parent = buffer[0];
		int idx = 1;
		
		// input handling
		while(idx < buffer.size()){
			
			if(buffer[idx] == ';'){
				
				idx++;
				parent = buffer[idx];
				
			}
			else if(isalpha(buffer[idx])){
				
				graph[parent - 'A'].push_back(buffer[idx] - 'A');
				
			}
			
			idx++;
			
		}
		
		dfs(m-'A', t-'A', 1);
		
	}
	
	return 0;
}
