#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int n, m, q;
bool win[1000][1000] = {false}; // win[a][b] -> [a] beats [b]

int main(){ BOOST

	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		
		int a, b;
		cin >> a >> b;
		
		win[a][b] = true;
		
	}
	
	cin >> q;
	for(int i=0;i<q;i++){
		
		int a, b;
		cin >> a >> b;
		
		cout << (win[a][b] ? "yes" : "no") << "\n";
		
	}
	
	return 0;
}
