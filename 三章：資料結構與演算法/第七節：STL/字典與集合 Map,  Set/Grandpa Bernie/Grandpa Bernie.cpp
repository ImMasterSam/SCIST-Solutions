#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	map<string, vector<int>> trip;

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		
		string name;
		int year;
		cin >> name >> year;
		
		trip[name].push_back(year);
		
	}
	
	for(auto &p : trip){
		
		sort(p.second.begin(), p.second.end());
		
	}
	
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		
		string place;
		int idx;
		cin >> place >> idx;
		cout << trip[place][idx-1] << "\n";
		
	}
	
	return 0;
}
