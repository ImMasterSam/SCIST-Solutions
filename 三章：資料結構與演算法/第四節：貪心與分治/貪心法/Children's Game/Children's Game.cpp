#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b){
	
	string A = a + b;
	string B = b + a;
	
	return A > B;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	
	while(cin >> n, n){
		
		vector<string> a(n);
		
		for(string &i : a)
			cin >> i;
			
		sort(a.begin(), a.end(), cmp);
		
		for(string &i : a)
			cout << i;
			
		cout << "\n";
		
	}
	
	return 0;
}