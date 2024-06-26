#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		int a[n];
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		sort(a, a+n);
		
		int l=0, r=n-1;
		
		long long ans = 0;
		
		while(l<r){
			
			ans += a[r--] - a[l++];
			
		}
		
		cout << ans << "\n";
		
		
		
	}
	
	return 0;
}