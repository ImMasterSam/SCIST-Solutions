#include <iostream>
using namespace std;

int n;

int grid[9][9] = {0};
bool row_flag[9][10] = {0};
bool col_flag[9][10] = {0};
bool square_flag[3][3][10] = {0};

bool found = false;

void dfs(int row, int col){
	
	if(row == n*n){
		
		for(int i=0;i<n*n;i++){
			
			for(int j=0;j<n*n;j++){
				
				if(j)
					cout << " ";
				cout << grid[i][j];
				
			}
			
			cout << "\n";
			
		}
		found = true;
		return;
		
	}
	
	else if (grid[row][col]){
		
		if(col == n*n-1)
			dfs(row+1, 0);
		else
			dfs(row, col+1);
			
		return;
		
	}
	
	for(int i=1;i<=n*n;i++){
		
		if(!row_flag[row][i] && !col_flag[col][i] && !square_flag[row/n][col/n][i]){
			
			row_flag[row][i] = col_flag[col][i] = square_flag[row/n][col/n][i] = true;
			grid[row][col] = i;
			
			if(col == n*n-1)
				dfs(row+1, 0);
			else
				dfs(row, col+1);
				
			if(found)
				return;
			
			row_flag[row][i] = col_flag[col][i] = square_flag[row/n][col/n][i] = false;
			grid[row][col] = 0;
			
		}
		
	}
	
}

void solve(){
	
	bool ill = false;
	
	for(int i=0;i<n*n;i++){
		
		for(int j=0;j<n*n;j++){
			
			int x;
			cin >> x;
			grid[i][j] = x;
			
			if(x){
				
				if(row_flag[i][x] || col_flag[j][x] || square_flag[i/n][j/n][x])
					ill = true;
				
				row_flag[i][x] = col_flag[j][x] = square_flag[i/n][j/n][x] = true;
				
			}
			
		}
		
	}
	
	found = false;
	
	if(ill)
		cout << "NO SOLUTION\n";
	else{
		
		dfs(0, 0);
		if(!found)
			cout << "NO SOLUTION\n";
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bool first = true;
	
	while(cin >> n){
		
		for(int i=0;i<9;i++){
			
			for(int j=0;j<10;j++){
				
				row_flag[i][j] = false;
				col_flag[i][j] = false;
				
			}
			
		}
		
		for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){
				
				for(int k=0;k<10;k++)
					square_flag[i][j][k] = false;
				
			}
			
		}
		
		if(!first)
			cout << "\n";
		
		solve();
		first = false;
		
	}
	
	return 0;
}