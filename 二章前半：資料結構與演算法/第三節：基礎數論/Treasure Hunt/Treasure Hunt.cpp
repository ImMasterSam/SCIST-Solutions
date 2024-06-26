#include<iostream>
using namespace std;

int main(){
	
	int r, c;
	cin >> r >> c;
	
	char map[r][c] = {0};
	int flag[r][c] = {0};
	
	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			flag[i][j] = 0;
		}
		
	}
	
	int x = 0, y = 0;
	int step = 0;
	
	while(1){
		
		flag[x][y] = 1;
		
		if(map[x][y] == 'T'){
			cout << step;
			break;
		}
		
		else if(map[x][y] == 'N'){
			
			x--;
			if(x<0){
				
				cout << "Out";
				break;
				
			}
			
		}
		else if(map[x][y] == 'S'){
			
			x++;
			if(x>=r){
				
				cout << "Out";
				break;
				
			}
			
		}
		else if(map[x][y] == 'W'){
			
			y--;
			if(y<0){
				
				cout << "Out";
				break;
				
			}
			
		}
		else if(map[x][y] == 'E'){
			
			y++;
			if(y>=c){
				
				cout << "Out";
				break;
				
			}
			
		}
			
		if(flag[x][y]){
			cout << "Lost";
			break;
		}
		
		step++;
		
	}
	
	return 0;
}