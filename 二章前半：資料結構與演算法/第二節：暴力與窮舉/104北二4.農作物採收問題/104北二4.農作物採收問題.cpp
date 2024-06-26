#include<iostream>
#include<climits>
using namespace std;

int main(){
	
	int n, in;
	
	while(cin >> n){
		
		int map[n+1][n+1] = {0};
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=n;j++){
				
				cin >> in;
				
				map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + in;
				
			}
			
		}
		
		long long max = LLONG_MIN+1;
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=n;j++){
				
				for(int x=i;x<=n;x++){
					
					for(int y=j;y<=n;y++){
						
						int sum = map[x][y] - map[x][j-1] - map[i-1][y] + map[i-1][j-1];
						
						if(sum > max)
							max = sum;
						
					}
					
				}
				
				
			}
			
		}
		
		cout << max << "\n";
		
	}
	
	
	return 0;
}