#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool graph[26][26] = {false};
bool vis[26] = {false};

void dfs(int cur){
	
	for(int i=0;i<26;i++){
		
		if(graph[cur][i] & !vis[i]){
			
			vis[i] = true;
			dfs(i);
			
		}
		
	}
	
}

int main(){ BOOST

	int n, m, k;
	cin >> n >> m >> k;
	
	char c;
	int arr[n][m] = {0};
	for(int i=0;i<n;i++){
		
		for(int j=0;j<m;j++){
			
			cin >> c;
			arr[i][j] = c - 'A';
			
		}
		
	}
	
	for(int i=0;i<m;i++){
		
		for(int j=1;j<n;j++){
			
			int x = arr[0][i];
			int y = arr[j][i];
			
			graph[x][y] = graph[y][x] = true;
			
		}
		
	}
	
	int cnt = 0;
	for(int i=0;i<k;i++){
		
		if(!vis[i]){
			
			dfs(i);
			cnt++;
			
		}
		
	}
	
	cout << cnt << "\n";
	
	return 0;
}
