#include <iostream>
using namespace std;

int n;
char map[5][5];

int MAX = 0;

bool check(int row, int col){

	for(int i=row-1, j=col;i>=0;i--){
		
		if(map[i][j] == 'X')
			break;
		
		if(map[i][j] == '#')
			return false;
		
	}
	
	for(int i=row, j=col-1;j>=0;j--){
		
		if(map[i][j] == 'X')
			break;
		
		if(map[i][j] == '#')
			return false;
		
	}
	
	return true;
	
}

void dfs(int row, int col, int rook){
	
	if(row == n){
		
		if(rook > MAX)
			MAX = rook;
		
		return;
		
	}
	
	if(map[row][col] == 'X'){
		
		if(col == n-1)
			dfs(row+1, 0, rook);
		else
			dfs(row, col+1, rook);
			
		return;
		
	}
	
	if(check(row, col)){
		
		map[row][col] = '#';
		
		if(col == n-1)
			dfs(row+1, 0, rook+1);
		else
			dfs(row, col+1, rook+1);
			
		map[row][col] = '.';
		
	}
		
	if(col == n-1)
		dfs(row+1, 0, rook);
	else
		dfs(row, col+1, rook);
	
}

int main(){
	
	while(cin >> n, n){
		
		MAX = 0;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> map[i][j];
		
		dfs(0, 0, 0);
		
		cout << MAX << "\n";
		
	}
	
	
	return 0;
}