#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

string handlestr(string s){
	
	for(char &c : s){
		
		if(isalpha(c))
			c = tolower(c);
		if(c == '-')
			c = ' ';
		
	}
	
	return s;
	
}

int main(){ BOOST

	int n;
	cin >> n;
	cin.ignore();
	
	set<string> SET;
	
	string s;
	for(int i=0;i<n;i++){
		
		getline(cin, s);
		s = handlestr(s);
		
		SET.insert(s);
		
	}
	
	cout << SET.size() << "\n";
	
	return 0;
}
