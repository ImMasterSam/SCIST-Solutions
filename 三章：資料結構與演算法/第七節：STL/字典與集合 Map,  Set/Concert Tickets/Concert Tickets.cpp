#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, m;
	cin >> n >> m;
	
	set<int, greater<int>> ticket;
	map<int, int> remain;
	
	for(int i=0;i<n;i++){
		
		int h;
		cin >> h;
		ticket.insert(h);
		remain[h]++;
		
	}
	
	for(int i=0;i<m;i++){
		
		int t;
		cin >> t;
		
		auto it = ticket.lower_bound(t);
		
		if(it != ticket.end()){
			
			int pay = *it;
			cout << pay << "\n";
			
			remain[pay]--;
			if(remain[pay] == 0)
				ticket.erase(pay);
			
		}
		else{
			
			cout << -1 << "\n";
			
		}
		
	}
	
	return 0;
}
