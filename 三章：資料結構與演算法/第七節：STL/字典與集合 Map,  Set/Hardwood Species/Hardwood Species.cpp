#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	map<string, int, less<string>> freq;
	
	string s;
	int n=0;
	while(getline(cin, s)){
		
		n++;
		freq[s]++;
		
	}
	
	for(auto &tree : freq){
		
		cout << tree.first << " ";
		double percent = (double)tree.second / n * 100.0;
		cout << fixed << setprecision(6) << percent << "\n";
		
	}
	
	return 0;
}
