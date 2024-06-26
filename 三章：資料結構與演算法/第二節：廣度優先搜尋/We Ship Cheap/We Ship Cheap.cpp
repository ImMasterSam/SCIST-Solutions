#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int m, n = 0;
bool side[700][700] = {0};
bool used[700] = {0};
pair<int, int> que[1000005]; // 0: idx, 1: last_que_idx;
unordered_map<string, int> name_idx;
unordered_map<int, string> idx_name;

void trace(int idx){
	
	pair<int, int> cur = que[idx];
	
	if(cur.s != -1){
		
		trace(cur.s);
		cout << idx_name[que[cur.s].f] << " " << idx_name[cur.f] << "\n";
		
	}
	
}

int bfs(int s, int e){
	
	pair<int, int> cur, nxt;
	
	cur.f = s;
	cur.s = -1;
	
	que[0] = cur;
	used[s] = true;
	
	int i, j;
	
	for(i=0, j=1;i<j;i++){
		
		cur = que[i];
		
		if(cur.f == e){
			
			return i;
			
		}
		
		for(int k=0;k<n;k++){
			
			if(side[cur.f][k] && !used[k]){
				
				nxt.f = k;
				nxt.s = i;
				
				used[k] = true;
				que[j++] = nxt;
				
			}
			
		}
		
	}
	
	return -1;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bool first = true;
	
	while(cin >> m){
		
		n = 0;
		name_idx.clear();
		idx_name.clear();
		memset(side, false, sizeof(side));
		memset(used, false, sizeof(used));
		
		string a, b;
		
		for(int i=0;i<m;i++){
			
			cin >> a >> b;
			
			if(name_idx.find(a) == name_idx.end()){
				
				name_idx[a] = n;
				idx_name[n++] = a;
				
			}
			
			if(name_idx.find(b) == name_idx.end()){
				
				name_idx[b] = n;
				idx_name[n++] = b;
				
			}
			
			side[name_idx[a]][name_idx[b]] = side[name_idx[b]][name_idx[a]] = true;
			
		}
		
		if(!first)
			cout << "\n";
		
		int start, end;
		cin >> a >> b;
		
		if(name_idx.find(a) == name_idx.end() || name_idx.find(b) == name_idx.end())
			cout << "No route\n";
			
		else{
			
			start = name_idx[a];
			end = name_idx[b];
			
			int last = bfs(start, end);
			
			if(last == -1)
				cout << "No route\n";
			else
				trace(last);
				
			first = false;
			
		}
			
		first = false;
		
	}
	
	return 0;
}