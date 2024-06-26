#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

long long pre[21][21][21] = {0};

int main(){ BOOST

	int t;
	cin >> t;
	
	bool first = true;
	
	while(t--){
		
		if(!first)
			cout << "\n";
		
		int A, B, C;
		cin >> A >> B >> C;
		
		long long temp;
		
		for(int z=1;z<=C;z++){
			
			for(int x=1;x<=A;x++){
				
				for(int y=1;y<=B;y++){
					
					cin >> temp;
					pre[x][y][z] = pre[x-1][y][z] + pre[x][y-1][z] - pre[x-1][y-1][z] + temp;
					
				}
				
			}
			
		}
		
		long long MAX = LLONG_MIN;
		
		for(int x=1;x<=A;x++){
			
			for(int y=1;y<=B;y++){
				
				for(int k=x;k<=A;k++){
					
					for(int l=y;l<=B;l++){
						
						long long dp[C+1];
						dp[1] = pre[k][l][1] - pre[x-1][l][1] - pre[k][y-1][1] + pre[x-1][y-1][1];
						
						MAX = max(MAX, dp[1]);
						
						for(int c=2;c<=C;c++){
							
							long long temp = pre[k][l][c] - pre[x-1][l][c] - pre[k][y-1][c] + pre[x-1][y-1][c];
							
							dp[c] = max(0LL, dp[c-1]) + temp;
							MAX = max(MAX, dp[c]);
							
						}
						
					}
					
				}
				
			}
			
		}
		
		cout << MAX << "\n";
		first = false;
		
	}
	
	return 0;
}
