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
		
		if(a[j] < a[l]){
			
			i++;
			swap(a[i], a[j]);
			
		}
		
	}
	
	swap(a[l], a[i]);
	
	QuickSort(a, l, i-1);
	QuickSort(a, i+1, r);
	
}

int main(){
	
	int a[6] = {5, 3, 6, 4, 1, 2};
	
	QuickSort(a, 0, 5);
	
	for(auto i : a)
		cout << i << " ";
	
	return 0;
}