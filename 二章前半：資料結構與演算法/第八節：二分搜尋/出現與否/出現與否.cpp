#include<iostream>
using namespace std;

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
	
}

void bubblesort(int *a, int n){
	
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-i-1;j++){
			
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
			}
			
		}
		
	}
	
}

bool binarysearch(int *a, int n, int val){
	
	int l=0, r=n-1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(a[mid] == val)
			return true;
		else if(a[mid] > val)
			r = mid - 1;
		else
			l = mid + 1;
		
	}
	
	return false;
	
}

int main(){
	
	int n, q, x;
	
	cin >> n >> q;
	
	int a[n];
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	bubblesort(a, n);
	
	for(int i=0;i<q;i++){
		
		cin >> x;
		
		if(binarysearch(a, n, x))
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	
	return 0;
}