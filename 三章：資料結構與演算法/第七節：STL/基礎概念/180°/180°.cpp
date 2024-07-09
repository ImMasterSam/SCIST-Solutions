#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

unordered_map<char, char> M = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

int main(){ BOOST

	vector<char> s;
	char c;
	
	while(cin >> c){
		
		s.push_back(c);
		
	}
	
	reverse(s.begin(), s.end());
	
	for(char x : s){
		
		cout << M[x];
		
	}
	
	return 0;
}
