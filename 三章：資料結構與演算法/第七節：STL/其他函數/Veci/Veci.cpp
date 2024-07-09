#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	string s;
	cin >> s;
	
	if(next_permutation(s.begin(), s.end()))
		cout << s << "\n";
	else
		cout << "0\n";
	
	return 0;
}
