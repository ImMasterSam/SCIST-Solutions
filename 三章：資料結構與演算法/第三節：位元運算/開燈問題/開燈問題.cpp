#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m;
	cin >> n >> m;
	
	int buttons[n+1] = {0};
	
	for(int i=1;i<=n;i++){
		
		int c;
		cin >> c;
		
		for(int j=0;j<c;j++){
			
			int x;
			cin >> x;
			
			buttons[i] |= (1 << (x-1));
			
		}
		
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		
		int p;
		cin >> p;
		
		int light = 0;
		
		for(int j=0;j<p;j++){
			
			int x;
			cin >> x;
			
			light ^= buttons[x];
			
		}
		
		for(int j=0;j<m;j++){
			
			cout << (light&1);
			
			light >>= 1;
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}