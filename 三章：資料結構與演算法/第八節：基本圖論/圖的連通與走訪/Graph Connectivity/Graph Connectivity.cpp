#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<vector<int>> graph(26);
bool vis[26] = {false};

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
	cin.ignore(2);
	
	for(int time=0;time<t;time++){
		
		if(time)
			cout << "\n";
		
		graph.assign(26, vector<int>());
		memset(vis, false, sizeof vis);
		
		char n;
		cin >> n;
		cin.ignore();
		
		string buffer;
		while(getline(cin, buffer)){
			
			if(buffer == "") break;
			
			int x = buffer[0] - 'A';
			int y = buffer[1] - 'A';
			
			graph[x].push_back(y);
			graph[y].push_back(x);
			
		}
		
		int count = 0;
		for(int i=0;i<=n-'A';i++){
			
			if(!vis[i]){
				
				dfs(i);
				count++;
				
			}
			
		}
		
		cout << count << "\n";
		
	}
	
	return 0;
}
