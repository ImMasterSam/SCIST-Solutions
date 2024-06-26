#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

bool dp[25][1000000] = {0};
int last[25][1000000] = {0};
bool choose[25] = {0};
int arr[25];

int main(){ BOOST

	int n, t;
	
	while(cin >> n >> t){
		
		memset(dp, false, sizeof dp);
		memset(last, 0, sizeof last);
		
		for(int i=0;i<t;i++)
			cin >> arr[i];
		
		dp[0][0] = true;
		dp[0][arr[0]] = (arr[0] <= n);
		
		for(int i=1;i<t;i++){
			
			for(int j=0;j<=n;j++){
				
				if(dp[i-1][j]){
					
					last[i][j] = j;
					dp[i][j] = true;
					
				}
				
				if(j - arr[i] >= 0){
					
					if(dp[i-1][j - arr[i]]){
						
						last[i][j] = j - arr[i];
						dp[i][j] = true;
						
					}
					
				}
				
			}
			
		}
		
		int MAX = 0;
		
		for(int i=n;i>=0;i--){
			
			if(dp[t-1][i]){
				
				MAX = i;
				break;
				
			}
			
		}
		
		int temp = MAX;
		memset(choose, false, sizeof choose);
		
		for(int i=t-1;i>=0;i--){
			
			if(last[i][temp] != temp)
				choose[i] = true;
			
			temp = last[i][temp];
			
		}
		
		for(int i=0;i<t;i++){
			
			if(choose[i])
				cout << arr[i] << " ";
			
		}
		
		
		cout << "sum:" << MAX << "\n";
		
	}
	
	return 0;
}
