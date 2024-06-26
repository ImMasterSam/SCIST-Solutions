#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	for(int time=0;time<n;time++){
		
		int p, k, l;
		cin >> p >> k >> l;
		
		int freq[l];
		
		for(int i=0;i<l;i++)
			cin >> freq[i];
			
		sort(freq, freq+l);
		
		int press = 1;
		int but = 0;
		
		long long ans = 0;
		
		for(int i=l-1;i>=0;i--){
			
			ans += press*freq[i];
			but++;
			
			if(but == k){
				
				press++;
				but = 0;
				
			}
			
		}
		
		cout << "Case #" << time+1 << ": " << ans << "\n";
		
	}
	
	return 0;
}