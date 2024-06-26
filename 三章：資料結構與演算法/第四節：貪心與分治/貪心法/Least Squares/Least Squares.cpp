#include <bits/stdc++.h>
using namespace std;

int m, n;
char board[100][80];
char ans[100][80];

void solve(int row, int col, char alpha){
	
	int size = 0;
	
	while(1){
		
		if(row+size>=m || col+size>=n)
			break;
		
		bool blocked = false;
		
		for(int i=0;i<size+1;i++){
			
			if(board[row+i][col+size] == '.')
				blocked = true;
			
		}
				
		for(int i=0;i<size+1;i++){
			
			if(board[row+size][col+i] == '.')
				blocked = true;
			
		}
				
		if(!blocked){
			
			for(int i=0;i<size+1;i++)
				ans[row+i][col+size] = alpha;
					
			for(int i=0;i<size+1;i++)
				ans[row+size][col+i] = alpha;
			
		}
		else
			break;
			
		size++;
		
	}
	
}

int main(){
	
	while(cin >> m >> n){
		
		if(m == 0 && n == 0)
			break;
		
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++)
				cin >> board[i][j];
			
		}
		
		memset(ans, 0, sizeof ans);
		
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++){
				
				if(board[i][j] == '.' || ans[i][j] >= 'A')
					continue;
				
				int dif = 0;
				if(i && ans[i-1][j] >= 'A')
					dif++;
				if(j && ans[i][j-1] >= 'A')
					dif++;
				
				solve(i, j, 'A'+dif);
				
			}
			
		}
		
		for(int i=0;i<m;i++){
			
			for(int j=0;j<n;j++){
				
				if(ans[i][j] != 0)
					cout << ans[i][j];
				else
					cout << '.';
				
			}
			cout << "\n";
			
		}
		
	}
	
	return 0;
}