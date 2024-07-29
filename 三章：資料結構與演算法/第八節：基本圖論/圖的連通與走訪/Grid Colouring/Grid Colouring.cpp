#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
vector<vector<char>> graph;
vector<vector<bool>> vis;

char wall = NULL;

bool check(string &s){
	
	for(char &c : s){
		
		if(c != '_')
			return false;
		
	}
	
	return true;
	
}

void dfs(int r, int c, char key){
	
	graph[r][c] = key;
	
	for(int d=0;d<4;d++){
		
		int row = r + dir[d][0];
		int col = c + dir[d][1];
		
		if(row >= 0 && row < graph.size()){
			
			if(col >= 0 && col < graph[row].size()){
				
				if(!vis[row][col] && graph[row][col] == ' '){
					
					vis[row][col];
					dfs(row, col, key);
					
				}
				
			}
			
		}
		
	}
	
}

int main(){ BOOST

	string buffer;
	while(getline(cin, buffer)){
		
		if(check(buffer)){
			
			n = graph.size();
			
			vis.assign(n, vector<bool>(m, false));
			
			for(int i=0;i<n;i++){
				
				for(int j=0;j<graph[i].size();j++){
					
					if(graph[i][j] != wall && graph[i][j] != ' '){
						
						if(!vis[i][j])
							dfs(i, j, graph[i][j]);
						
					}
					
				}
				
			}
			
			for(int i=0;i<n;i++){
				
				for(int j=0;j<graph[i].size();j++)
					cout << graph[i][j];
				cout << "\n";
				
			}
			
			cout << buffer << "\n";
			
			graph.clear();
			m = 0;
			wall = NULL;
		}
		else{
			
			vector<char> temp;
			for(char c : buffer){
				
				if(c!=' ' && wall == NULL)
					wall = c;
				
				temp.push_back(c);
				
			}
				
				
			m = max(m, (int)buffer.size());
				
			graph.push_back(temp);
			
		}
		
	}
	
	return 0;
}
