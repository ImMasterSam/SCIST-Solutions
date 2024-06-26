#include <iostream>
#include <algorithm>
using namespace std;
/*
#define min(a, b) (a<b ? a: b)
#define abs(a) (-a)*/

int main(){
	
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		
		int x;
		cin >> x;
		
		int l = 0, r = n-1;
		int it = -1;
		
		while(l<=r){
			
			int mid = (l+r)/2;
			
			if(a[mid] < x){
				
				it = mid;
				l = mid + 1;
				
			}
			else
				r = mid - 1;
			
		}
		
		//cout << it << "\n";
		
		int ans = 1e9;
		
		if(it != -1)
			ans = min(ans, x - a[it]);
		if(it != n-1)
			ans = min(ans, a[it+1] - x);
		
		cout << ans << "\n";
		
	}
	
	
	return 0;
}