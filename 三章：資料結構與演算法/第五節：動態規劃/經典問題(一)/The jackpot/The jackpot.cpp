#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	
	while(cin >> n, n){
		
		int arr[n];
		int dp[n] = {0};
		int MAX = 0;
		
		for(int i=0;i<n;i++)
			cin >> arr[i];
		
		dp[0] = arr[0];
			
		for(int i=1;i<n;i++){
			
			dp[i] = max(0, dp[i-1]) + arr[i];
			
			MAX = max(MAX, dp[i]);
			
		}
		
		if(MAX)
			cout << "The maximum winning streak is " << MAX << ".\n";
		else
			cout << "Losing streak.\n";
		
	}
	
	return 0;
}
