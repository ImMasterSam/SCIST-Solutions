#include<iostream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int times=0;times<t;times++){
		
		int nc=0, ne=0, ans=0;
		double sc=0, se=0;
		cin >> nc >> ne;
		long long c[nc], e;
		
		for(int i=0;i<nc;i++){
			cin >> c[i];
			sc += c[i];
		}
		
		for(int i=0;i<ne;i++){
			cin >> e;
			se += e;
		}
		
		double ac=sc/nc, ae=se/ne;
		
		//cout << ac << " " << ae << "\n";
		
		for(int i=0;i<nc;i++){
			
			if(c[i]<ac && c[i]>ae)
				ans++;
			
		}
		
		cout << ans << "\n";
		
	}
		
	return 0;
}