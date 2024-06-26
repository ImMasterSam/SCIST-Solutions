#include <iostream>
using namespace std;

int ans = 0;
int tbl[10] = {0};

void dfs(int depth, int target, long long total, long long d){
	
	if(depth == target){
		
		if(total%d == 0){
			
			ans++;
			return;
			
		}
		
	}
	
	for(int i=0;i<10;i++){
		
		if(tbl[i]){
			
			tbl[i]--;
			dfs(depth+1, target, total*10 + i, d);
			tbl[i]++;
			
		}
		
	}
	
	
}

void solve(string &s, long long d){
	
	for(int i=0;i<10;i++)
		tbl[i] = 0;
	
	for(int i=0;i<s.size();i++)
		tbl[s[i]-'0']++;
		
	dfs(0, s.size(), 0, d);
	
}

int main(){
	
	int n;
	cin >> n;
	
	while(n--){
		
		string s;
		long long d;
		cin >> s >> d;
		ans = 0;
		
		solve(s, d);
		
		cout << ans << "\n";
		
	}
	
	return 0;
}