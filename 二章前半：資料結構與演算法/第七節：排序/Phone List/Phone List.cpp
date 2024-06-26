#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	vector<string> v;
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		v.assign(n, "");
		
		for(int i=0;i<n;i++)
			cin >> v[i];
			
		sort(v.begin(), v.end());
		
		bool consistent = true;
		
		for(int i=0;i<n-1;i++){
			
			int l = v[i].size();
			
			if(v[i] == v[i+1].substr(0, l)){
				
				consistent = false;
				break;
				
			}
			
		}
		
		cout << (consistent ? "YES\n" : "NO\n");
		
	}
	
	
	return 0;
}