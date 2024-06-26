#include<iostream>
using namespace std;

void swap(int &a, int &b){
	
	int t = a;
	a = b;
	b = t;
	
}

void QuickSort(int a[], int l, int r){
	
	if(l >= r)	
		return;
		
	int i, j;
	
	for(i=l, j=l+1; j <= r; j++){
		
		if(a[j] > a[l]){
			
			i++;
			swap(a[i], a[j]);
			
		}
		
	}
	
	swap(a[l], a[i]);
	
	QuickSort(a, l, i-1);
	QuickSort(a, i+1, r);
	
}

int main(){
	
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	QuickSort(a, 0, n-1);
	
	int k;
	cin >> k;
	
	for(int i=0;i<k;i++){
		
		int x;
		cin >> x;
		
		cout << a[x-1] << "\n";
		
	} 
	
	
	return 0;
}