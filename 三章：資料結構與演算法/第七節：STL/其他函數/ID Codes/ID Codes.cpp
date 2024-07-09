#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	string s;
	
	while(cin >> s){
		
		if(s == "#") break;
		
		if(next_permutation(s.begin(), s.end()))
			cout << s << "\n";
		else
			cout << "No Successor\n";
		
	}
	
	return 0;
}
