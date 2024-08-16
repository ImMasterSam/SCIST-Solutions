#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;
/*
	看到這題請趕快跳過 (強烈建議 ! ! ! )
*/
const int n = 8;
const char target[2] = {'K', 'k'};

#define inside(x) (x >= 0 && x < n ? 1 : 0)

bool check[2] = {false};
char board[n][n] = {0};

void pawn(bool iswhite, int r, int c){
	
	const int dir[2] = {1, -1};
	int dr = (iswhite ? -1 : 1);
	
	for(int d=0;d<2;d++){
		
		int nxtr = r + dr;
		int nxtc = c + dir[d];
		
		if(inside(nxtr) && inside(nxtc)){
			
			if(board[nxtr][nxtc] == target[iswhite]){
				
				check[iswhite] = true;
				//cout << "check by: " << board[r][c] << "\n";
				
			}
			
		}
		
	}
	
}

void knight(bool iswhite, int r, int c){
	
	const int dir[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
	
	for(int d=0;d<8;d++){
		
		int nxtr = r + dir[d][0];
		int nxtc = c + dir[d][1];
		
		if(inside(nxtr) && inside(nxtc)){
			
			if(board[nxtr][nxtc] == target[iswhite]){
				
				check[iswhite] = true;
				//cout << "check by: " << board[r][c] << "\n";
				
			}
			
		}
		
	}
	
}

void bishop(bool iswhite, int r, int c){
	
	const int dir[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
	
	for(int d=0;d<4;d++){
		
		int nxtr = r + dir[d][0];
		int nxtc = c + dir[d][1];
		
		while(inside(nxtr) && inside(nxtc)){
			
			if(board[nxtr][nxtc] != '.'){
				
				if(board[nxtr][nxtc] == target[iswhite]){
					
					check[iswhite] = true;
					//cout << "check by: " << board[r][c] << "\n";
					
				}
				
				break;
				
			}
			
			nxtr += dir[d][0];
			nxtc += dir[d][1];
			
		}
		
	}
	
}

void rook(bool iswhite, int r, int c){
	
	const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	
	for(int d=0;d<4;d++){
		
		int nxtr = r + dir[d][0];
		int nxtc = c + dir[d][1];
		
		while(inside(nxtr) && inside(nxtc)){
			
			if(board[nxtr][nxtc] != '.'){
				
				if(board[nxtr][nxtc] == target[iswhite]){
					
					check[iswhite] = true;
					//cout << "check by: " << board[r][c] << "\n";
					
				}
				
				break;
				
			}
			
			nxtr += dir[d][0];
			nxtc += dir[d][1];
			
		}
		
	}
	
}

void queen(bool iswhite, int r, int c){
	
	const int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
	
	for(int d=0;d<8;d++){
		
		int nxtr = r + dir[d][0];
		int nxtc = c + dir[d][1];
		
		while(inside(nxtr) && inside(nxtc)){
			
			if(board[nxtr][nxtc] != '.'){
				
				if(board[nxtr][nxtc] == target[iswhite]){
					
					check[iswhite] = true;
					//cout << "check by: " << board[r][c] << "\n";
					
				}
				
				break;
				
			}
			
			nxtr += dir[d][0];
			nxtc += dir[d][1];
			
		}
		
	}
	
}

int main(){ BOOST

	int game = 1;
	
	while(1){
		
		// reset
		
		check[0] = check[1] = false;
		
		// Input
		
		bool stop = true;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> board[i][j];
				
				if(board[i][j] != '.')
					stop = false;
				
			}
			
		}
		
		if(stop)
			break;
			
		// process
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				switch(board[i][j]){
					
					case 'p':
					case 'P':
						pawn(isupper(board[i][j]), i, j);
						break;
					
					case 'n':
					case 'N':
						knight(isupper(board[i][j]), i, j);
						break;
					
					case 'b':
					case 'B':
						bishop(isupper(board[i][j]), i, j);
						break;
					
					case 'r':
					case 'R':
						rook(isupper(board[i][j]), i, j);
						break;
					
					case 'Q':
					case 'q':
						queen(isupper(board[i][j]), i, j);
						break;
						
					default:
						break;
					
				}
				
			}
			
		}
			
		// Output
			
		cout << "Game #" << game++ << ": ";
		if(check[0])
			cout << "white king is in check.";
		else if(check[1])
			cout << "black king is in check.";
		else
			cout << "no king is in check.";
		cout << "\n";
		
	}

		
	
	return 0;
}
