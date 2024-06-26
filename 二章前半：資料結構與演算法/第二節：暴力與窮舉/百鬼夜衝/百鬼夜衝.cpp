#include<iostream>
using namespace std;

int main(){
	
	int order[3][3] = {0};
	
	int power[9][4] = {0};
	
	string input;
	
	for(int i=0;i<3;i++){
		
		cin >> input;
		
		for(int j=0;j<3;j++){
			
			order[i][j] = input[j] - '0';
			
		}
		
	}
	
	char alpha[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	
	for(int i=0;i<9;i++){
		
		cin >> input;
		
		for(int j=0;j<4;j++){
			
			for(int k=0;k<16;k++){
				
				if(alpha[k] == input[j]){
					
					power[i][j] = k;
					break;
					
				}
				
			}
			
		}
		
	}
	/*
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout << order[i][j] << " ";
		cout << "\n";
		
	}*/
	
	
	int flag[2][9] = {0};
	
	int ord = 0;
	
	while(ord < 9){
		
		for(int x=0;x<3;x++){
			
			for(int y=0;y<3;y++){
				
				if(order[x][y] == ord){
					
					// up
					if(x>0 && order[x-1][y] < ord){
						
						if(power[order[x-1][y]][3] <= power[ord][0]){
							
							flag[0][order[x-1][y]] = 0;
							flag[1][order[x-1][y]] = 0;
							flag[ord%2][order[x-1][y]] = 1;
							
						}	
						
					}
					
					// right
					if(y>0 && order[x][y-1] < ord){
						
						if(power[order[x][y-1]][2] <= power[ord][1]){
							
							flag[0][order[x][y-1]] = 0;
							flag[1][order[x][y-1]] = 0;
							flag[ord%2][order[x][y-1]] = 1;
							
						}	
						
					}
					
					// left
					if(y<2 && order[x][y+1] < ord){
						
						if(power[order[x][y+1]][1] <= power[ord][2]){
							
							flag[0][order[x][y+1]] = 0;
							flag[1][order[x][y+1]] = 0;
							flag[ord%2][order[x][y+1]] = 1;
							
						}	
						
					}
					
					// down
					if(x<2 && order[x+1][y] < ord){
						
						if(power[order[x+1][y]][0] <= power[ord][3]){
							
							flag[0][order[x+1][y]] = 0;
							flag[1][order[x+1][y]] = 0;
							flag[ord%2][order[x+1][y]] = 1;
							
						}	
						
					}
					
					flag[ord%2][ord] = 1;
					
				}
				
			}
			
		}
		/*
		cout << "order: " << ord << "\n";
		
		for(int i=0;i<2;i++){
			
			for(int j=0;j<9;j++)
				cout << flag[i][j] << " ";
			
			cout << "\n";
			
		}*/
			
		ord++;
		
	}
	
	int A=0, B=0;
			
	for(int j=0;j<9;j++){
		
		if(flag[0][j])
			A++;
		if(flag[1][j])
			B++;
		
	}
		
	cout << A << "-" << B << "\n";
	
	
	return 0;
}
