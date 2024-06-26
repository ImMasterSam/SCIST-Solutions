#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		int k;
		cin >> k;
		
		int total = 0;
		
		for(int i=0;i<k;i++){
			
			int x;
			cin >> x;
			total += x;
			
		}
		
		cout << total - (k - 1) << "\n";
		
	}
	
	return 0;
}
