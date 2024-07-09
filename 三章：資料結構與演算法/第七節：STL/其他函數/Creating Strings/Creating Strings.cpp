#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	vector<string> ans;
	do{
		
		ans.push_back(s);
		
	}while(next_permutation(s.begin(), s.end()));
	
	cout << ans.size() << "\n";
	for(string &str : ans)
		cout << str << "\n";
	
	return 0;
}
