#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	set<string> SET;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		
		string s;
		cin >> s;
		
		if(!SET.count(s)){
			
			cout << i << "\n";
			SET.insert(s);
			
		}
		
	}
	
	return 0;
}
