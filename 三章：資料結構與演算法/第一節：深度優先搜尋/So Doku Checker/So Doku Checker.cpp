#include <iostream>
using namespace std;

int grid[9][9] = {0};
bool row_flag[9][10] = {0};
bool col_flag[9][10] = {0};
bool square_flag[3][3][10] = {0};

int ans = 0;

void dfs(int row, int col){
	
	if(row == 9){
		
		ans++;
		return;
		
	}
	
	else if (grid[row][col]){
		
		if(col == 8)
			dfs(row+1, 0);
		else
			dfs(row, col+1);
			
		return;
		
	}
	
	for(int i=1;i<=9;i++){
		
		if(!row_flag[row][i] && !col_flag[col][i] && !square_flag[row/3][col/3][i]){
			
			row_flag[row][i] = col_flag[col][i] = square_flag[row/3][col/3][i] = true;
			grid[row][col] = i;
			
			if(col == 8)
				dfs(row+1, 0);
			else
				dfs(row, col+1);
				
			if(ans > 1)
				return;
			
			row_flag[row][i] = col_flag[col][i] = square_flag[row/3][col/3][i] = false;
			grid[row][col] = 0;
			
		}
		
	}
	
}

void solve(){
	
	row_flag[0][grid[0][0]] = col_flag[0][grid[0][0]] = square_flag[0][0][grid[0][0]] = true;
	
	bool ill = false;
	
	for(int i=0;i<9;i++){
		
		for(int j=0;j<9;j++){
			
			if(i==0&&j==0)
				continue;
			
			int x;
			cin >> x;
			grid[i][j] = x;
			
			if(x){
				
				if(row_flag[i][x] || col_flag[j][x] || square_flag[i/3][j/3][x])
					ill = true;
					
				row_flag[i][x] = col_flag[j][x] = square_flag[i/3][j/3][x] = true;
				
			}
			
		}
		
	}
	
	if(ill)
		cout << "Illegal.\n";
	else{
		
		dfs(0, 0);
		
		if(!ans)
			cout << "Impossible.\n";
		else if(ans == 1)
			cout << "Unique.\n";
		else
			cout << "Ambiguous.\n";
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int times = 1;
	
	while(cin >> grid[0][0]){
		
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
		
		ans = 0;
		
		cout << "Case " << times++ << ": ";
		
		solve();
		
	}
	
	return 0;
}