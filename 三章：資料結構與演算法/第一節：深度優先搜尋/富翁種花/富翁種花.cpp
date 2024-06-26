#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<char, int> flower = {{'R', 1}, {'O', 2}, {'Y', 3},
						 {'G', 4}, {'B', 5}, {'I', 6},
						 {'P', 7}, {'L', 8}, {'W', 9}};
						 
map<int , char> num = {{1, 'R'}, {2, 'O'}, {3, 'Y'},
					  {4, 'G'}, {5, 'B'}, {6, 'I'},
					  {7, 'P'}, {8, 'L'}, {9, 'W'}};
						 
int grid[9][9] = {0};
int temp[9][9] = {0};
bool row_flag[9][10] = {0};
bool col_flag[9][10] = {0};
bool square_flag[3][3][10] = {0};

void dfs(int row, int col){
	
	if(row == 9){
		
		for(int i=0;i<9;i++){
			
			for(int j=0;j<9;j++){
				
				if(grid[i][j] != temp[i][j])
					cout << num[grid[i][j]];
				
			}
			
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
			
			char c;
			cin >> c;
			
			if(c == '*'){
				
				grid[i][j] = 0;
				temp[i][j] = 0;
				
			}
			else{
				
				int x = flower[c];
				grid[i][j] = x;
				temp[i][j] = x;
				row_flag[i][x] = col_flag[j][x] = square_flag[i/3][j/3][x] = true;
				
			}
			
		}
		
	}
	
	dfs(0, 0);
	/*
	for(int i=0;i<9;i++){
		
		for(int j=0;j<9;j++)
			cout << grid[i][j] << " ";
		cout << "\n";
		
	}*/
	
	
	return 0;
}