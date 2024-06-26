#include<iostream>
using namespace std;

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int n;
		cin >> n;
		
		int map[n][n] = {0};
		
		for(int i=0;i<n;i++){
			
			char c;
			
			for(int j=0;j<n;j++){
				
				cin >> c;
				map[i][j] = c - '0';
				
			}
			
		}
		
		int m;
		cin >> m;
		
		for(int mo=0;mo<m;mo++){
			
			string move;
			cin >> move;
			
			if(move == "row"){
				
				int r1, r2;
				cin >> r1 >> r2;
				for(int i=0;i<n;i++)
					swap(&map[r1-1][i], &map[r2-1][i]);
				
			}
			
			else if(move == "col"){
				
				int c1, c2;
				cin >> c1 >> c2;
				for(int i=0;i<n;i++)
					swap(&map[i][c1-1], &map[i][c2-1]);
				
			}
			
			else if(move == "inc"){
				
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						map[i][j] = (map[i][j]+1)%10;
				
			}
			else if(move == "dec"){
				
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						map[i][j] = (map[i][j]+9)%10;
				
			}
			else if(move == "transpose"){
				
				int temp[n][n] = {0};
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						temp[j][i] = map[i][j];
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						map[i][j] = temp[i][j];
				
			}
			
			
		}
		
		cout << "Case #" << time+1 << "\n";
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++)
				cout << map[i][j];
			cout << "\n";
			
		}
		
		cout << "\n";
		
	}
	
	
	return 0;
}