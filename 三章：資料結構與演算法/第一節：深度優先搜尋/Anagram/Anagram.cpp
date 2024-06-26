#include <iostream>
using namespace std;

int tbl[128] = {0};
char path[10000];

void dfs(int depth, int target){
	
	if(depth == target){
		
		path[depth] = 0;
		cout << path << "\n";
		
	}
	
	for(int i='A';i<='Z';i++){
		
		if(tbl[i]){
			
			tbl[i]--;
			path[depth] = i;
			dfs(depth+1, target);
			tbl[i]++;
			
		}
		
		int lower = i + 32;
		
		if(tbl[lower]){
			
			tbl[lower]--;
			path[depth] = lower;
			dfs(depth+1, target);
			tbl[lower]++;
			
		}
		
	}
	
}

void solve(string &s){
	
	for(int i='A';i<='Z';i++){
		
		tbl[i] = 0;
		tbl[i+32] = 0;
		
	}
		
	for(int i=0;i<s.size();i++)
		tbl[s[i]]++;
		
	dfs(0, s.size());
	
}

int main(){
	
	string s;
	int n;
	cin >> n;
	
	cin.ignore();
	
	while(n--){
		
		cin >> s;
		
		solve(s);
		
	}
	
	return 0;
}