#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> W_idx;

void bfs(){
	
	int idx = 0;
	queue<string> q;
	string cur;
	
	q.push("");
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		W_idx[cur] = idx++;
		
		if(cur.size() == 5)
			continue;
		
		for(int i=0;i<26;i++){
			
			if(cur == "" || (char)(i+'a') > cur[cur.size()-1])
				q.push(cur + (char)(i+'a'));
			
		}
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bfs();
	
	string s;
	while(cin >> s){
		
		cout << W_idx[s] << "\n";
		
	}
	
	return 0;
}