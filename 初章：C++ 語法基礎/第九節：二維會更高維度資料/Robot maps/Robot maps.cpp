#include<iostream>
using namespace std;

int main(){
	
	int n, m, x, y, times=0;
	cin >> n >> m;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout << (int)see[i][j] << " ";
		cout << "\n";
	}
	*/
	while(n!=0 && m!=0){
		
		char map[15][15] = {0};
		char see[15][15] = {0};
		int  pass[15][15] = {0};
		
		cin >> y >> x;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cin >> map[i][j];
		}
		
		bool running = true;
		int step = 0;
		
		while(running){
			
			see[y][x] = '0';
			
			//observe
			if(map[y-1][x]!=0){
				if(map[y-1][x] == 'X')
					see[y-1][x] = 'X';
				else if(map[y-1][x] == '0')
					see[y-1][x] = '0';
			}
			if(map[y][x+1]!=0){
				if(map[y][x+1] == 'X')
					see[y][x+1] = 'X';
				else if(map[y][x+1] == '0')
					see[y][x+1] = '0';
			}
			if(map[y+1][x]!=0){
				if(map[y+1][x] == 'X')
					see[y+1][x] = 'X';
				else if(map[y+1][x] == '0')
					see[y+1][x] = '0';
			}
			if(map[y][x-1]!=0){
				if(map[y][x-1] == 'X')
					see[y][x-1] = 'X';
				else if(map[y][x-1] == '0')
					see[y][x-1] = '0';
			}
			/*
			cout << step << " :";
			cout << x << " " << y << "\n";
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(see[i][j] == 0)
						cout << "? ";
					else
						cout << see[i][j] << " ";
				}
				cout << "\n";
			}*/
			
			//walk
			if(map[y-1][x]!=0 && pass[y-1][x]==0 && see[y-1][x]!='X'){
				pass[y][x]=1;
				y--;
				step++;
			}
			else if(map[y][x+1]!=0 && pass[y][x+1]==0 && see[y][x+1]!='X'){
				pass[y][x]=1;
				x++;
				step++;
			}
			else if(map[y+1][x]!=0 && pass[y+1][x]==0 && see[y+1][x]!='X'){
				pass[y][x]=1;
				y++;
				step++;
			}
			else if(map[y][x-1]!=0 && pass[y][x-1]==0 && see[y][x-1]!='X'){
				pass[y][x]=1;
				x--;
				step++;
			}
			else
				running = false;
			
			
		}
		cout << "\n";
		for(int i=0;i<n*2;i++){
			cout << '|';
			if(i%2==0){
				for(int j=0;j<m*4;j++){
					if(j%4==3)
						cout << '|';
					else
						cout << '-';
				}
			}
			else{
				for(int j=0;j<m*4;j++){
					if(j%4==0 || j%4==2)
						cout << ' ';
					else if(j%4==1){
						if(see[(i/2)+1][(j/4)+1]==0)
							cout << '?';
						else
							cout << see[(i/2)+1][(j/4)+1];
					}
					else if(j%4==3)
						cout << '|';
				}
			}
			cout << "\n";
		}
		
		cout << '|';
		for(int j=0;j<m*4;j++){
			if(j%4==3)
				cout << '|';
			else
				cout << '-';
		}
		cout << "\n\nNUMBER OF MOVEMENTS: " << step << "\n";
		
		cin >> n >> m;
	}
		
	return 0;
}