#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	string a[n];
	int len = 0;
	
	unordered_map<string, int> freq;
	unordered_set<string> color;
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		
		cin >> a[i];
		freq[a[i]]++;
		color.insert(a[i]);
		len++;
		
		if(len > m){
			
			string x = a[i-len+1];
			
			freq[x]--;
			if(freq[x] < 1)
				color.erase(x);
			
			len--;
		}
		
		if(len==m && color.size() == m)
			ans++;
		
	}
	
	cout << ans;
	
	return 0;
}