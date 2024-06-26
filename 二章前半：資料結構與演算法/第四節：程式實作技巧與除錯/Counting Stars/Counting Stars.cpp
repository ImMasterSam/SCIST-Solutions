#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	long long a[n+1] = {0};
	
	for(int i=1;i<=n;i++){
		
		long long x;
		cin >> x;
		
		a[i] = a[i-1] + x;
		
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		
		int l, r;
		cin >> l >> r;
		
		if(l > r){
			
			int t = l;
			l = r;
			r = t;
			
		}
		
		cout << a[r] - a[l-1] << "\n";
		
	}
	
	return 0;
}