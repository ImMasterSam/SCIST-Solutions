#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;


// 這題我的父子節點整個寫反了
// 但是不影響結果
// 只是反著做回來而已

vector<int> arr(26, -1);
vector<vector<int>> edge(26, vector<int>());

int topo(){
	
	queue<int> que;
	vector<int> finish(26, -1);
	vector<int> ind(26, 0);
	
	for(int i=0;i<26;i++){
		
		for(int j : edge[i]){
			
			ind[j]++;
			
		}
		
	}
	
	for(int i=0;i<26;i++){
		
		if(!ind[i] && arr[i] != -1){
			
			que.push(i);
			finish[i] = 0;
			
		}
		
	}
	
	while(!que.empty()){
		
		int t = que.front();
		que.pop();
		
		finish[t] += arr[t];
		
		for(int i : edge[t]){
			
			finish[i] = max(finish[i], finish[t]);
			
			if(!(--ind[i])){
				
				que.push(i);
				
			}
			
		}
		
	}
	
	int ans = 0;
	for(int i=0;i<26;i++){
		
		ans = max(ans, finish[i]);
		
	}
	
	return ans;
	
}

int main(){ BOOST

	bool first = true;

	int t;
	cin >> t;
	cin.ignore(2);
	
	while(t--){
		
		string buffer;
		arr.assign(26, -1);
		edge.assign(26, vector<int>());
		
		while(getline(cin, buffer), buffer != ""){
			
			char start;
			int weight;
			char children[26] = {0};
			
			sscanf(buffer.c_str(), "%c %d %[^\n]", &start, &weight, children);
			
			arr[start - 'A'] = weight;
			for(int i=0;i<strlen(children);i++){
				
				int child = children[i] - 'A';
				edge[start - 'A'].push_back(child);
				
			}
			
		}
		
		if(!first)
			cout << "\n";
		
		int ans = topo();
		cout << ans << "\n";
		
		first = false;
		
	}	
		
	
	return 0;
}
