#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool exist[26] = {false};
vector<vector<int>> edge(26, vector<int>());

void cmp(string a, string b){
	
	for(char &c : a)
		exist[c - 'A'] = true;
	for(char &c : b)
		exist[c - 'A'] = true;
	
	int idx = 0;
	while(idx < a.size() && idx < b.size()){
		
		if(a[idx] != b[idx]){
			
			edge[a[idx] - 'A'].push_back(b[idx] - 'A');
			break;
			
		}
		
		idx++;
		
	}
	
	
}

void toposort(){
	
	vector<int> ind(26, 0);
	queue<int> que;
	
	for(int i=0;i<26;i++){
		
		for(int j : edge[i]){
			
			ind[j]++;
			
		}
		
	}
	
	for(int i=0;i<26;i++){
		
		if(!ind[i] && exist[i]){
			
			que.push(i);
			
		}
		
	}
	
	vector<char> res;
	
	while(que.size()){
		
		int t = que.front();
		que.pop();
		
		res.push_back((char)(t + 'A'));
		
		for(int i : edge[t]){
			
			if(!(--ind[i])){
				
				que.push(i);
				
			}
			
		}
		
	}
	
	for(char i : res)
		cout << i;
	cout << endl;
	
}

int main(){ BOOST
	
	string cur;
	string nxt;
	
	while(cin >> cur){
		
		memset(exist, false, sizeof exist);
		edge.assign(26, vector<int>());
		
		cmp(cur, cur);
		
		while(cin >> nxt, nxt != "#"){
			
			cmp(cur, nxt);
			
			cur = nxt;
			
		}
		
		toposort();
		
	}	
	
	return 0;
}
