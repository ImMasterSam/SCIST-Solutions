#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> relation(n+1);
	
	for(int i=0;i<k;i++){
		
		int a, b;
		cin >> a >> b;
		
		relation[a].push_back(b);
		relation[b].push_back(a);
		
	}
	
	for(int i=1;i<=n;i++){
		
		sort(relation[i].begin(), relation[i].end());
		
		bool first = true;
		
		for(int &x : relation[i]){
			
			if(!first)
				cout << " ";
			
			cout << x;
			first = false;
			
		}
		cout << "\n";
		
	}
	
	return 0;
}
