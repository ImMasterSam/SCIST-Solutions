#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int x[10] = {0};
int y[10] = {0};

int cuts[10][10] = {0};
int dp[10][10] = {0};

void dfs(int i, int j){
	
	if(i == j){
		
		cout << "A" << i+1;
		return;
		
	}
	
	cout << "(";
	
	dfs(i, cuts[i][j]);
	cout << " x ";
	dfs(cuts[i][j]+1, j);
	cout << ")";
	
}

int main(){ BOOST

	int time = 1;

	int n;
	while(cin >> n, n){
		
		cout << "Case " << time++ << ": ";
		
		memset(dp, 0, sizeof dp);
		for(int i=0;i<n;i++)
			cin >> x[i] >> y[i];
			
		for(int len=2;len<=n;len++){
			
			for(int i=0;i+len-1<n;i++){
				
				int j = i + len - 1;
				
				int cut = 0;
				int temp = INT_MAX;
				
				for(int k=i;k<j;k++){
					
					if(dp[i][k] + dp[k+1][j] + (x[i]*y[k]*y[j]) <= temp){
						
						//cout << i << ", " << j << ", cuts: " << k << "->" << (x[i]*y[k]*y[j]) << "\n"; 
						
						temp = dp[i][k] + dp[k+1][j] + (x[i]*y[k]*y[j]);
						cut = k;
						
					}
					
				}
				
				dp[i][j] = temp;
				cuts[i][j] = cut;
				
			}
			
		}
		
		dfs(0, n-1);
		cout << "\n";
		/*
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++)
				cout << dp[i][j] << " ";
			cout << "\n";
		}
		for(int i=0;i<n;i++){
			
			for(int j=0;j<n;j++)
				cout << cuts[i][j] << " ";
			cout << "\n";
		}
		*/
	}
	
	return 0;
}
