#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, m;
	cin >> n >> m;
	
	vector<int> count(n+1, 0);
	for(int i=0;i<m;i++){
		
		int a, b;
		cin >> a >> b;
		
		if(a < b)
			count[b]++;
		
		if(b < a)
			count[a]++;
		
	}
	
	int ans = 0;
	
	for(int i=1;i<=n;i++){
		
		if(count[i] == 1)
			ans++;
		
	}
	
	cout << ans << "\n";
		
	
	return 0;
}
