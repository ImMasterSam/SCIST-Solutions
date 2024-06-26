#include<iostream>
using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int main(){
	
	int t;
	
	cin >> t;
	
	for(int times=0;times<t;times++){
		
		int r, c;
		
		cin >> r >> c;
		cin.ignore();
		
		string map[c];
		
		for(int i=0;i<r;i++){
			
			getline(cin, map[i]);
			
		}
		
		int x, y, d = 0;
		char ch;
		
		cin >> y >> x;
		x--;y--;
		
		cin >> ch;
		while(ch != 'Q'){
			
			switch(ch){
				
				case 'R':
					d = (d+1)%4;
					break;
				case 'L':
					d = (d+3)%4;
					break;
				
				case 'F':
					if(map[y+dir[d][1]][x+dir[d][0]] == ' '){
						
						x += dir[d][0];
						y += dir[d][1];
						
					}
					break;
				
			}
			
			cin >> ch;
			
		}
		
		cout << y+1 << " " << x+1 << " ";
		
		switch(d){
			
			case 0:
				cout << "N\n";
				break;
			case 1:
				cout << "E\n";
				break;
			case 2:
				cout << "S\n";
				break;
			case 3:
				cout << "W\n";
				break;
			
		}
		
		if(times!=t-1)
			cout << "\n";
		
		/*
		for(int i=0;i<r;i++){
			
			cout << map[i] << "\n";
			
		}*/
		
	}
	
	
	return 0;
}