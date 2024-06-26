#include<iostream>
using namespace std;

char alpha[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

int main(){
	
	int n;
	
	cin >> n;
	
	string s[3][3];
	
	for(int times=0;times<n;times++){
		
		for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){
				
				cin >> s[i][j];
				
			}
			
		}
		
		int fake = -1;
		int weight = -1;
		
		for(int f=0;f<12;f++){
			
			int islight = -1;
			bool isfake = true;
			
			for(int g=0;g<3&&isfake;g++){
				
				int group = -1;
				
				for(int i=0;i<s[g][0].size();i++){
					if(s[g][0][i] == alpha[f])
						group = 0;
				}
				
				for(int i=0;i<s[g][1].size();i++){
					if(s[g][1][i] == alpha[f])
						group = 1;
				}
				
				if(group == -1 && s[g][2] != "even")
					isfake = false;
					
				else if(group == 0){
					
					if(s[g][2] == "even")
						isfake = false;
					else if(s[g][2] == "up"){
						
						if(islight == -1)
							islight = 0;
						else if (islight == 1)
							isfake = false;
						
					}
					
					else if(s[g][2] == "down"){
						
						if(islight == -1)
							islight = 1;
						else if (islight == 0)
							isfake = false;
						
					}
					
				}
				
				else if(group == 1){
					
					if(s[g][2] == "even")
						isfake = false;
					else if(s[g][2] == "up"){
						
						if(islight == -1)
							islight = 1;
						else if (islight == 0)
							isfake = false;
						
					}
					
					else if(s[g][2] == "down"){
						
						if(islight == -1)
							islight = 0;
						else if (islight == 1)
							isfake = false;
						
					}
					
				} 
				
			}
			
			if(isfake){
				fake = f;
				weight = islight;
				break;
			}
			
		}
		
		cout << alpha[fake] << " is the counterfeit coin and it is ";
		if(weight)
			cout << "light.\n";
		else
			cout << "heavy.\n";
		
		/*for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){
				
				cout << s[i][j] << " ";
				
			}
			
			cout << "\n";
			
		}*/
		
	}
	
	return 0;
}