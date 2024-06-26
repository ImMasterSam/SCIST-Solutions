#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int mask = 0;
int board[15] = {0};

// p: attack from ↙
// q: attack from ↘
// r: attack from ↓ 

void dfs(int depth, int p, int q, int r){
	
	if(depth == n){
		
		ans++;
		return;
		
	}
	
	int avail = ~(p | q | r | board[depth]) & mask;
	
	while(avail){
		
		int last = (avail & -avail);
		
		dfs(depth+1, (p|last)<<1, (q|last)>>1, (r|last));
		
		avail &= ~last;
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int time = 1;
	
	while(cin >> n, n){
		
		ans = 0;
		mask = (1 << n) - 1; //to filter over bound bits;
		memset(board, 0, sizeof(board));
		
		char c;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> c;
				
				board[i] <<= 1;
				
				if(c == '*')
					board[i]++;
				
			}
			
		}
		
		dfs(0, 0, 0, 0);
		
		cout << "Case " << time++ << ": ";
		
		cout << ans << "\n";
		
	}
	
	return 0;
}