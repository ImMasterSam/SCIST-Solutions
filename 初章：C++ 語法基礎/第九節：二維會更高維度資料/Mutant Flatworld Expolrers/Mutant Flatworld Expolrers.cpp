#include<iostream>
using namespace std;

char face[4] = {'N', 'E', 'S', 'W'};
int m[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int f[60][60] = {0};

int main(){
	
	int r, c;
	cin >> c >> r;
	
	int x, y, d;
	char direction;
	string command;
	
	while(cin >> x >> y >> direction){
		
		bool moving = true;
		
		if(direction=='N') d = 0;
		else if(direction=='E') d = 1;
		else if(direction=='S') d = 2;
		else if(direction=='W') d = 3;
		
		cin >> command;
		
		for(int i=0;i<(int)command.size() and moving;i++){
			
			if(command[i]=='R')
				d = (d+1)%4;
			else if(command[i]=='L')
				d = (d+3)%4;
			
			else if(command[i]=='F'){
				
				if(x+m[d][0]>c or x+m[d][0]<0 or y+m[d][1]>r or y+m[d][1]<0){
					if(f[y][x]==0){
						cout << x << " " << y << " " << face[d] << " LOST\n";
						moving = false;
						f[y][x]++;	
					}
				}
				
				else{
					x += m[d][0];
					y += m[d][1];
				} 
				
			}
			//cout << x << " " << y << " " << face[d] << "\n";
			
		}
		
		if(moving)
			cout << x << " " << y << " " << face[d] << "\n";
		
	}
		
	return 0;
}