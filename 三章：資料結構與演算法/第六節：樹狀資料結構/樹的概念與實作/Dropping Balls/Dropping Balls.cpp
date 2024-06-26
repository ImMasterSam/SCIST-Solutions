#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		int d, l;
		cin >> d >> l;
		int cur = 1;
		
		for(int depth=1;depth<d;depth++){
			
			if(l&1){
				
				cur <<= 1;
				l = (l >> 1) + 1;
				
			}
			else{
				
				cur = (cur << 1) + 1;
				l >>= 1;
				
			}
			
		}
		
		cout << cur << "\n";
		
	}
	
	return 0;
}
