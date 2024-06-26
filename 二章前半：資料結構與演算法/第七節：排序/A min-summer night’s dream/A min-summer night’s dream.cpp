#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n){
		
		int a[n];
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		sort(a, a+n);
		
		// odd
		if(n%2){
			
			int mid = n/2;
			
			cout << a[mid] << " ";
			
			int l=mid, r=mid;
			
			while(l && a[l-1] == a[mid]) l--;
			while(r<n-1 && a[r+1] == a[mid]) r++;
			
			cout << r-l+1 << " ";
			
			cout << 1 << "\n";
			
		}
		
		else{
			
			int mid = n/2 - 1;
			
			cout << a[mid] << " ";
			
			int l = mid, r = mid+1;
			
			while(l && a[l-1] == a[mid]) l--;
			while(r<n-1 && a[r+1] == a[mid+1]) r++;
			
			cout << r-l+1 << " ";
			
			cout << a[r] - a[l] + 1 << "\n";
			
		}
		
	}
	
	
	return 0;
}