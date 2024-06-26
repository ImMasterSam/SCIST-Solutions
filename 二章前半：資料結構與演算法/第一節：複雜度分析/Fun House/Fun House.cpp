#include<iostream>
using namespace std;

char map[25][25] = {0};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
	
	int r, c, times = 1;
	char in;
	int sx, sy;
	int d = 0;
	
	cin >> c >> r;
	
	while(r != 0 && c != 0){
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> in;
				map[i][j] = in;
				if(in == '*'){
					sx = j;sy = i;
					if(i == 0)
						d = 1;
					if(i == r-1)
						d = 3;
					if(j == 0)
						d = 0;
					if(j == c-1)
						d = 2;
				}
			}
		}
		
		while(map[sy][sx] != 'x'){
			
			if(map[sy][sx] == '\\'){
				
				if(d == 0)
					d = 1;
				else if(d == 1)
					d = 0;
				else if(d == 2)
					d = 3;
				else if(d == 3)
					d = 2;
				
			}
			
			if(map[sy][sx] == '/'){
				
				if(d == 0)
					d = 3;
				else if(d == 1)
					d = 2;
				else if(d == 2)
					d = 1;
				else if(d == 3)
					d = 0;
				
			}
			
			
			sx += dir[d][0]; sy += dir[d][1];
		}
		
		map[sy][sx] = '&';
		
		cout << "HOUSE " << times++ << "\n";
		
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cout << map[i][j];
			cout << "\n";
		}
		
		cin >> c >> r;
	}
	
	return 0;
}