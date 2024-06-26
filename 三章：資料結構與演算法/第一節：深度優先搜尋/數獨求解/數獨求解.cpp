#include <iostream>
using namespace std;

int grid[9][9] = {0};
bool row_flag[9][10] = {0};
bool col_flag[9][10] = {0};
bool square_flag[3][3][10] = {0};

void dfs(int row, int col){
	
	if(row == 9){
		
		for(int i=0;i<9;i++){
			
			for(int j=0;j<9;j++)
				cout << grid[i][j] << " ";
			
			cout << "\n";
			
		}
		
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
			
			row_flag[row][i] = col_flag[col][i] = square_flag[row/3][col/3][i] = false;
			grid[row][col] = 0;
			
		}
		
	}
	
}

int main(){
	
	for(int i=0;i<9;i++){
		
		for(int j=0;j<9;j++){
			
			int x;
			cin >> x;
			grid[i][j] = x;
				
			row_flag[i][x] = col_flag[j][x] = square_flag[i/3][j/3][x] = true;
			
		}
		
	}
	
	dfs(0, 0);
	
	return 0;
}