#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	
	while(cin >> n >> m, (n||m)){
		
		int heads[n];
		int knights[m];
		
		for(int i=0;i<n;i++)
			cin >> heads[i];
		for(int i=0;i<m;i++)
			cin >> knights[i];
			
		sort(heads, heads+n);
		sort(knights, knights+m);
		
		bool kill = true;
		int ans = 0;
		int j=0;
		
		for(int i=0;i<n;i++){
			
			for(;j<m && knights[j]<heads[i];j++);
			
			if(j >= m){
				
				kill = false;
				break;
				
			}
			
			ans += knights[j];
			j++;
			
		}
		
		if(kill)
			cout << ans << "\n";
		else
			cout << "Loowater is doomed!\n";		
	}
	
	return 0;
}