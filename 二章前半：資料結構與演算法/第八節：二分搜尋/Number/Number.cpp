#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int a[], int n, int x){
	
	int l = 0, r = n-1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(a[mid] == x)
			return mid;
		else if(a[mid] < x)
			l = mid+1;
		else
			r = mid-1;
		
	}
	
	return -1;
	
}

int main(){
	
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	int m;
	cin >> m;
	
	for(int i=0;i<m;i++){
		
		int x;
		cin >> x;
		
		int idx = BinarySearch(a, n, x);
		
		if(idx == -1)
			cout << "0\n";
			
		else{
			
			int l, r;
			l = r = idx;
			
			while(l && a[l-1] == a[l]) l--;
			while(r < n-1 && a[r+1] == a[r]) r++;
			
			cout << r-l+1 << "\n";
			
		}
		
	}
	
	return 0;
}