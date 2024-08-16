#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	string s;
	
	while(getline(cin, s)){
		
		for(char &c : s)
			cout << (char)(c - 7);
		cout << "\n";
		
	}
	
	return 0;
}
