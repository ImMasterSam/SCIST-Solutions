#include<iostream>
#include<climits>
using namespace std;

char alpha[3] = {'B', 'G', 'C'};

int main(){
	
	int bottles[3][3];
	
	while(cin >> bottles[0][0]){
		
		int min = INT_MAX-1;
		string ans = "ZZZ";
		
		for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){
				
				if(i==0 && j==0)
					continue;
				
				cin >> bottles[i][j];
				
			}
			
		}
		
		for(int i=0;i<3;i++){
			
			for(int j=0;j<3;j++){
				
				if(j==i)
					continue;
				
				for(int k=0;k<3;k++){
					
					int sum = 0;
					
					if(k==i || k==j)
						continue;
						
					for(int x=0;x<3;x++){
						
						if(x==i)
							continue;
							
						sum += bottles[0][x];
						
					}	
					for(int x=0;x<3;x++){
						
						if(x==j)
							continue;
							
						sum += bottles[1][x];
						
					}	
					for(int x=0;x<3;x++){
						
						if(x==k)
							continue;
							
						sum += bottles[2][x];
						
					}
					
					if(sum < min){
						
						ans = "";
						ans += alpha[i];
						ans += alpha[j];
						ans += alpha[k];
						min = sum;
											
					}
					else if (sum == min){
						
						string temp = "";
						
						temp += alpha[i];
						temp += alpha[j];
						temp += alpha[k];
						
						if(temp < ans)
							ans = temp;
						
					}
					
				}
				
			}
			
		}
		
		cout << ans << " " << min << "\n";
		
	}
	
	return 0;
}