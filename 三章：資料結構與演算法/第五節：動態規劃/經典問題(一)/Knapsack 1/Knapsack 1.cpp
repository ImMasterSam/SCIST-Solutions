#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

long long dp[2][100010] = {0};

int main(){ BOOST
	
	int n, W;
	cin >> n >> W;
	
	long long w[n], v[n];
	
	long long *a = dp[0];
	long long *b = dp[1];
	
	long long MAX = 0;
	
	for(int i=0;i<n;i++)
		cin >> w[i] >> v[i];
	
	a[w[0]] = v[0];
	MAX = max(MAX, v[0]);
	
	for(int i=1;i<n;i++){
		
		swap(a, b);
		
		for(int j=0;j<=W;j++){
			
			long long temp = 0;
			
			if(j >= w[i])
				temp = max(temp, b[j - w[i]] + v[i]);
			
			temp = max(temp, b[j]);
			
			a[j] = temp;
			MAX = max(MAX, temp);
			
		}
		
	}
	
	cout << MAX << "\n";
	
	return 0;
}
