#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	vector<pair<int, string>> mount;
	
	for(int i=0;i<n;i++){
		
		string name;
		int h;
		cin >> name >> h;
		
		mount.emplace_back(h, name);
		
	}
	
	sort(mount.begin(), mount.end(), greater<pair<int, string>>());
	
	cout << mount[1].second << "\n";
	
	return 0;
}
