#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, m;
	cin >> n >> m;
	
	int a, b;
	vector<vector<int>> fight(n+1);
	
	for(int i=0;i<m;i++){
		
		cin >> a >> b;
		fight[a].push_back(b);
		
	}
	
	int q, x, y;
	cin >> q;
	for(int i=0;i<q;i++){
		
		cin >> x >> y;
		
		if(fight[x].size() < y){
			
			cout << "-1\n";
			
		}
		else{
			
			cout << fight[x][y-1] << "\n";
			
		}
		
	}
	
	return 0;
}
