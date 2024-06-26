#include <bits/stdc++.h>
using namespace std;

int n;
string strs[100];

void solve(){
	
	sort(strs, strs+n);
	
	int ans = strs[0].size();
	
	for(int i=1;i<n;i++){
		
		if(strs[i][0] != strs[i-1][0]){
			
			ans += strs[i].size();
			continue;
			
		}
		
		int j, k;
		for(j=0, k=0;j<strs[i].size();j++, k++){
			
			if(strs[i][j] != strs[i-1][j])
				break;
			
		}
		
		ans += strs[i].size() - k;
		
	}
	
	cout << ans << "\n";
	for(int i=0;i<n;i++)
		cout << strs[i] << "\n";
	
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		cin >> n;
		
		for(int i=0;i<n;i++)
			cin >> strs[i];
			
		solve();
		
	}
	
	
	return 0;
}