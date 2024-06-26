#include <iostream>
using namespace std;

int n, m;
int res[128] = {0};

void dfs(int depth, int start){
	
	if(depth == m){
		
		for(int i=0;i<m;i++){
			
			if(i)
				cout << " ";
			
			cout << res[i];
			
		}
		
		cout << "\n";
		return;
		
	}
	
	for(int i=start;i<=n;i++){
		
		res[depth] = i;
		dfs(depth+1, i+1);
		
	}
	
}

int main(){
	
	cin >> n >> m;
	
	dfs(0, 1);
	
	return 0;
}