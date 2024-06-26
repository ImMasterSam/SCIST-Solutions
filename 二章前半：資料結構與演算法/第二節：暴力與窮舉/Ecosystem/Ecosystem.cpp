#include<iostream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	
	while(cin >> n){
		
		int flag[n][n];
		int count = 0;
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++){
				
				cin >> flag[i][j];
				
			}
			
		}
		
		for(int i=0;i<n;i++){
			
			for(int j=i+1;j<n;j++){
				
				for(int k=j+1;k<n;k++){
					
					if(flag[i][j] && flag[j][k] && flag[k][i]){
						
						cout << i+1 << " " << j+1 << " " << k+1 << "\n";
						count++;
						
					}
					
				}
				
			}
			
		}
		
		for(int i=0;i<n;i++){
			
			for(int j=i+1;j<n;j++){
				
				for(int k=j+1;k<n;k++){
					
					if(flag[k][j] && flag[j][i] && flag[i][k]){
						
						cout << k+1 << " " << j+1 << " " << i+1 << "\n";
						count++;
						
					}
					
				}
				
			}
			
		}
		
		cout << "total:" << count << "\n\n";
		
	}
	
	return 0;
}