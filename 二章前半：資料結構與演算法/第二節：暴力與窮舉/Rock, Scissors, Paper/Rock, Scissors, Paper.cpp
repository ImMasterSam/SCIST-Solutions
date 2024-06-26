#include<iostream>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		if(time > 0)
			cout << "\n";
			
		int r, c, n;
		
		cin >> r >> c >> n;
		
		char map[r][c];
		char temp[r][c];
				
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++){
				
				cin >> map[i][j];
				
			}
			
		}
		
		for(int days=0;days<n;days++){
			
			for(int i=0;i<r;i++){
				
				for(int j=0;j<c;j++){
					
					int R=0, p=0, s=0;
					
					if(i>0){
						
						switch(map[i-1][j]){
							
							case 'R':
								R++;
								break;
							case 'P':
								p++;
								break;
							case 'S':
								s++;
								break;
							
						}

					}
					
					if(i<r-1){
						
						switch(map[i+1][j]){
							
							case 'R':
								R++;
								break;
							case 'P':
								p++;
								break;
							case 'S':
								s++;
								break;
							
						}

					}
					
					if(j>0){
						
						switch(map[i][j-1]){
							
							case 'R':
								R++;
								break;
							case 'P':
								p++;
								break;
							case 'S':
								s++;
								break;
							
						}

					}
					
					if(j<c-1){
						
						switch(map[i][j+1]){
							
							case 'R':
								R++;
								break;
							case 'P':
								p++;
								break;
							case 'S':
								s++;
								break;
							
						}

					}
					
					switch(map[i][j]){
						
						case 'R':
							if(p)
								temp[i][j] = 'P';
							else
								temp[i][j] = 'R';
							break;
							
						case 'P':
							if(s)
								temp[i][j] = 'S';
							else
								temp[i][j] = 'P';
							break;
							
						case 'S':
							if(R)
								temp[i][j] = 'R';
							else
								temp[i][j] = 'S';
							break;	
						
					}
					
				}
				
			}
			
			for(int i=0;i<r;i++){
				
				for(int j=0;j<c;j++)
					map[i][j] = temp[i][j];
				
			}
			/*
			for(int i=0;i<r;i++){
				
				for(int j=0;j<c;j++)
					cout << map[i][j];
					
				cout << "\n";
			}*/
			
		}
		
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++)
				cout << map[i][j];
				
			cout << "\n";
		}
		
		
	}
		
	return 0;
}