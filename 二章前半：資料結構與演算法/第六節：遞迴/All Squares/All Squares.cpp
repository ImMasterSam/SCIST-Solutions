#include<iostream>
#include<iomanip>
using namespace std;

int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int dfs(int k, int n, int m, int x, int y){
	
	int ans = 0;
	
	if(k){
		
		if(n+k>=x&&n-k<=x  && m+k>=y&&m-k<=y)
			ans++;
		
		for(int i=0;i<4;i++){
			
			ans += dfs(k/2, n+dir[i][0]*k, m+dir[i][1]*k, x, y);
			
		}
		
	}
	
	return ans;
	
}

int main(){
	
	int k, x, y;

	while(cin >> k >> x >> y){
		
		if(k==0 && x==0 && y==0)
			break;
		else
			cout << setw(3) << dfs(k, 1024, 1024, x, y) << "\n";
		
	}	
	
	return 0;
}