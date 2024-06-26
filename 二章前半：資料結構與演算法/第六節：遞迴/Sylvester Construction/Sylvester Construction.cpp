#include<iostream>
using namespace std;

int H[2][2] = {{1, 1}, {1, -1}};

int solve(long long n, long long j, long long i){
	
	if(n == 1)
		return 1;
		
	else if (n == 2){
		
		return H[i][j];
		
	}
	
	else{
		
		int x = j;
		if(x >= n/2)
			x -= n/2;
		int y = i;
		if(y >= n/2)
			 y -= n/2;
		
		if(i>=n/2 && j>=n/2)
			return -solve(n/2, x, y);
		else
			return solve(n/2, x, y);
		
	}
	
}

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		long long n, x, y, w, h;
		
		cin >> n >> x >> y >> w >> h;
		
		for(int i=y;i<y+h;i++){
			
			for(int j=x;j<x+w;j++){
				
				cout << solve(n, j, i) << " ";
				
			}
			
			cout << "\n";
			
		}
		
		cout << "\n";
	}
	
	return 0;
}