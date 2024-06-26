#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, i;
	vector<int> v;
	
	while(cin >> n){
		
		v.resize(n);
		for(i=0;i<n;i++)
			cin >> v[i];
		
		sort(v.begin(), v.end());
		
		for(vector<int>::iterator it=v.begin();it!=v.end();it++){
			
			cout << *it << "\n";
			
		}
		
	}
	
	return 0;
}