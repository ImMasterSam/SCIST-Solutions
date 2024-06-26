#include <iostream>
using namespace std;

bool side[6][6] = {0};
int path[9], vis[6][6];

void dfs(int depth, int last){
	
	if(depth == 9){
		
		for(int i=0;i<9;i++)
			cout << path[i];
		cout << "\n";
		return;
		
	}
	
	for(int i=1;i<6;i++){
		
		if(!vis[last][i] && !vis[i][last] && side[last][i]){
			
			vis[last][i] = vis[i][last] = true;
			path[depth] = i;
			dfs(depth+1, i);
			vis[last][i] = vis[i][last] = false;
			
		}
		
	}
	
}

int main(){
	
	side[1][2] = side[1][3] = side[1][5] = true;
	side[2][1] = side[2][3] = side[2][5] = true;
	side[3][1] = side[3][2] = side[3][4] = side[3][5] = true;
	side[4][3] = side[4][5] = true;
	side[5][1] = side[5][2] = side[5][3] = side[5][4] = true;
	path[0]=1;
	
	dfs(1, 1);
	
	return 0;
}