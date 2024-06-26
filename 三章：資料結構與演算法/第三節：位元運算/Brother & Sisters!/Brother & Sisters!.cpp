#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n, q;
		cin >> n >> q;
		
		unsigned int a[n];
		unsigned int ans[230];
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		for(unsigned int i=0;i<230;i++){
			
			unsigned int max = 0;
			
			for(int j=0;j<n;j++){
				
				if((i & a[j]) > max)
					max = (i & a[j]);
				
			}
			
			ans[i] = max;
			
		}
			
		for(int i=0;i<q;i++){
			
			unsigned int A;
			cin >> A;
			
			cout << ans[A] << "\n";
			
		}
		
	}
	
	return 0;
}