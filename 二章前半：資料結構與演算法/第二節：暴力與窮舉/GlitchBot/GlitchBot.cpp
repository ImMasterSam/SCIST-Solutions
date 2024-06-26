#include<iostream>
using namespace std;

string temp[3] = {"Forward", "Left", "Right"};
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(){
	
	int dx, dy;
	int step;
	
	cin >> dx >> dy;
	cin >> step;
	
	string com[step];
	
	for(int i=0;i<step;i++)
		cin >> com[i];
		
	bool found = false;
	
	for(int i=0;i<step;i++){
		
		for(int j=0;j<3;j++){
			
			int x=0, y=0, d = 0;
			
			if(com[i] == temp[j])
				continue;
			
			for(int k=0;k<step;k++){
				
				string command;
				
				if(i == k)
					command = temp[j];
				else
					command = com[k];
					
				if(command == "Forward"){
					x += dir[d][0];
					y += dir[d][1];
				}
				else if (command == "Right"){
					d = (d+1)%4;
				}
				else if (command == "Left"){
					d = (d+3)%4;
				}
				
				
			}
			
			if(x == dx && y == dy){
				
				cout << i+1 << " " << temp[j] << "\n";
				found = true;
				break;
				
			}
			
		}
		
		if(found)
			break;
		
	}
	
	return 0;
}