#include <iostream>
using namespace std;

int n;
int a, b, c;

string puzzles[100][30];
bool used[100] = {0};
int shapes[100][4];

int graph[100][100];

void dfs(int row, int col){
	
	if(row == a){
		
		for(int i=0;i<a;i++){
			
			for(int j=0;j<b;j++){
				
				for(int k=0;k<a;k++){
					
					cout << puzzles[graph[i][k]][j];
					
				}
				cout << "\n";
				
			}
			
		}
		
		return;
		
	}
	
	for(int i=0;i<a*a;i++){ 
		
		if(used[i])
			continue;
		/*
		cout << "idx: " << i << "\n";
		cout << row << " : " << col << "\n"; 
		*/
		if(row == 0 && shapes[i][0] != 0)
			continue;
		if(col == 0 && shapes[i][1] != 0)
			continue;
		if(row == a-1 && shapes[i][2] != 0)
			continue;
		if(col == a-1 && shapes[i][3] != 0)
			continue;
		
		if(row > 0 && shapes[i][0] == 0)
			continue;
		if(col > 0 && shapes[i][1] == 0)
			continue;
		if(row < a-1 && shapes[i][2] == 0)
			continue;
		if(col < a-1 && shapes[i][3] == 0)
			continue;
		
		bool yes = true;
		
		if(row){
			
			if(shapes[i][0] + shapes[graph[row-1][col]][2] != 0)
				yes = false;
			
		}
		
		if(col){
			
			if(shapes[i][1] + shapes[graph[row][col-1]][3] != 0)
				yes = false;
			
		}
			
		if(!yes)
			continue;
		
		graph[row][col] = i;
		used[i] = true;
		
		if(col == a-1)
			dfs(row+1, 0);
		else
			dfs(row, col+1);
		
		graph[row][col] = 0;
		used[i] = false;
		
	}
	
}

int main(){
	
	bool first = true;
	cin >> n;
	
	while(n--){
		
		cin >> a >> b >> c;
		
		cin.ignore();
		
		for(int i=0;i<a*a;i++){
			
			used[i] = false;
			
			for(int j=0;j<b;j++)
				getline(cin, puzzles[i][j]);
				
			for(int j=0;j<4;j++)
				cin >> shapes[i][j];
				
			cin.ignore();
			cin.ignore();
			
		}
		
		if(!first)
			cout << "\n";
		
		dfs(0, 0);
		first = false;
		/*
		for(int i=0;i<a*a;i++){
			
			for(int j=0;j<b;j++)
				cout << puzzles[i][j] << "\n";
			
			cout << "\n";
			
		}*/
		
	}
	
	
	return 0;
}