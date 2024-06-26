#include <iostream>
using namespace std;

int n;
bool add[30] = {0};
bool sub[30] = {0};
bool col[15] = {0};

int ans = 0;

void dfs(int row){
	
	if(row == n){
		
		ans++;
		return;
		
	}
	
	for(int i=0;i<n;i++){
		
		if(!col[i] && !add[row+i] && !sub[row-i+n]){
			
			col[i] = true;
			add[row+i] = true;
			sub[row-i+n] = true;
			dfs(row+1);
			col[i] = false;
			add[row+i] = false;
			sub[row-i+n] = false;
			
		}
		
	}
	
}

int main(){
	
	cin >> n;
	
	dfs(0);
	
	cout << ans;
	
	return 0;
}