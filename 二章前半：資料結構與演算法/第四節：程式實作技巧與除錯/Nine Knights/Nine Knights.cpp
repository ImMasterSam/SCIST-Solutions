#include<iostream>
using namespace std;

int d[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int main(){
	
	char map[5][5];
	int count = 0;
	
	for(int i=0;i<5;i++){
		
		for(int j=0;j<5;j++){
			
			cin >> map[i][j];
			if(map[i][j] == 'k')
				count++;
			
		}
		
	}
	
	bool valid = true;
	
	for(int i=0;i<5 && valid;i++){
		
		for(int j=0;j<5 && valid;j++){
			
			if(map[i][j] == '.')
				continue;
				
			for(int k=0;k<8;k++){
				
				int x = i+d[k][0];
				int y = j+d[k][1];
				
				if((x>=0&&x<5) && (y>=0&&y<5)){
					
					if(map[x][y] == 'k')
						valid = false;
					
				}
				
			}
			
			
		}
		
	}
	
	cout << ((valid && count == 9) ? "valid": "invalid");
	
	return 0;
}