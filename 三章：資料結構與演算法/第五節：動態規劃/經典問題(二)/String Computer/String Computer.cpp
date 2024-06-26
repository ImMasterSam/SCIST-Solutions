#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<vector<int>> dp; //紀錄操作變化量
vector<vector<int>> pre;
string a, b;

void print(int i, int j){
	
	if(i==0 && j == 0) return;
	
	switch(pre[i][j]){
		
		case 1:
			print(i-1, j-1);
			break;
		case 2:
			print(i-1, j);
			printf("D%c%02d", a[i-1], j+1);
			break;
		case 3:
			print(i, j-1);
			printf("I%c%02d", b[j-1], j);
			break;
		case 4:
			print(i-1, j-1);
			printf("C%c%02d", b[j-1], j);
			break;
		
	}
	
}

int main(){ //BOOST
	
	while(cin >> a){
		
		if(a == "#") break;
		cin >> b;
		
		dp.assign(a.size()+1, vector<int> (b.size()+1, 4000));
		pre.assign(a.size()+1, vector<int> (b.size()+1, -1));
		
		for(int i=0;i<=a.size();i++){
			
			pre[i][0] = 2;
			dp[i][0] = i;
			
		}
		for(int i=0;i<=b.size();i++){
			
			pre[0][i] = 3;
			dp[0][i] = i;
			
		}
		
		for(int i=1;i<=a.size();i++){
			
			for(int j=1;j<=b.size();j++){
				
				if(a[i-1] == b[j-1] && dp[i][j] > dp[i-1][j-1]){
					
					dp[i][j] = dp[i-1][j-1];
					pre[i][j] = 1;
					
				}
				else{
					
					dp[i][j] = dp[i-1][j-1] + 1;
					pre[i][j] = 4;
					
				}
				
				if(dp[i][j] > dp[i][j-1]+1){
					
					dp[i][j] = dp[i][j-1] + 1;
					pre[i][j] = 3;
					
				}
				if(dp[i][j] > dp[i-1][j]+1){
					
					dp[i][j] = dp[i-1][j] + 1;
					pre[i][j] = 2;
					
				}
				
			}
			
		}
		
		print(a.size(), b.size());
		cout << "E\n";
		
	}
	
	return 0;
}
