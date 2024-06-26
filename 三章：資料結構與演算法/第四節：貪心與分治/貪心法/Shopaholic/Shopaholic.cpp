#include <bits/stdc++.h>
using namespace std;

int a[20000] = {0};

bool cmp(const int &a, const int &b){
	
	return a > b;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		sort(a, a+n, cmp);
		
		int save = 0;
		
		for(int i=2;i<n;i+=3){
			
			save += a[i];
			
		}
		
		cout << save << "\n";
		
	}
	
	return 0;
}