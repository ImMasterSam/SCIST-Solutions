#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, m, w, h;
	cin >> n >> m >> h >> w;
	
	vector<vector<long long>> pre(n+1, vector<long long> (m+1, 0));
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			
			int x;
			cin >> x;
			
			pre[i][j] = x + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			
		}
		
	}
	
	long long MAX = LLONG_MIN;
	int mi = -1, mj = -1;
	
	for(int i=1;i+h-1<=n;i++){
		
		for(int j=1;j+w-1<=m;j++){
			
			int x = i+h-1;
			int y = j+w-1;
			
			long long temp = pre[x][y] - pre[i-1][y] - pre[x][j-1] + pre[i-1][j-1];
			
			if(temp >= MAX){
				
				MAX = temp;
				mi = i-1;
				mj = j-1;
				
			}
			
		}
		
	}
	
	cout << mi << " " << mj << " " << MAX;
	
	return 0;
}
