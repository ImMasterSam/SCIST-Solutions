#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	cin >> n >> m;
	
	int features[1024] = {0};
	
	for(int i=0;i<n;i++){
		
		int c;
		cin >> c;
		
		for(int j=0;j<c;j++){
			
			int x;
			cin >> x;
			features[i] |= (1 << x);
			
		}
		
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		
		int p;
		cin >> p;
		
		int req = 0; // mask
		
		for(int j=0;j<p;j++){
			
			int x;
			cin >> x;
			
			req |= (1 << x);
			
		}
		
		int count = 0;
		
		for(int j=0;j<n;j++){
			
			if((req&features[j]))
				count++;
			
		}
		
		cout << count << "\n";
		
	}
	
	return 0;
}