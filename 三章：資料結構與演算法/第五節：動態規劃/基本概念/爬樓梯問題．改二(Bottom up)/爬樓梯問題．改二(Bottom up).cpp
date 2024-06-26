#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int arr[101];
	bool dp[101][10] = {0};
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> arr[i];
		
	dp[0][0] = true;
		
	for(int i=1;i<=n;i++){
		
		for(int j=0;j<10;j++){
					
			if(i-1>=0 && dp[i-1][j])
				dp[i][(j + arr[i])%10] = true;
			
			if(i-2>=0 && dp[i-2][j])
				dp[i][(j + arr[i])%10] = true;
			
		}
		
	}
	
	for(int i=0;i<10;i++){
		
		if(dp[n][i]){
			
			cout << i << "\n";
			break;
			
		}
		
	}
	
	return 0;
}