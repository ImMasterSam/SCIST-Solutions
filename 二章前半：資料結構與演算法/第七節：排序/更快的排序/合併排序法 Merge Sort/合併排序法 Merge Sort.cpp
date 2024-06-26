#include<iostream>
using namespace std;

void Merge(int a[], int n, int l, int r){
	
	int mid, i, j, k;
	int temp[n] = {0};
	
	mid = (l+r)/2;
	
	i = l;
	j = mid + 1;
	
	for(k=l;k<=r;k++){
		
		if( i<=mid && (j>r || a[i]<a[j])){
			
			temp[k] = a[i++];
			
		}
		
		else{
			
			temp[k] = a[j++];
			
		}
		
	}
	
	for(k=l;k<=r;k++){
		
		a[k] = temp[k];
		
	}
	
}

void MergeSort(int a[], int n, int l, int r){
	
	if(l == r)
		return;
		
	int mid = (l+r)/2;
	
	MergeSort(a, n, l, mid);
	MergeSort(a, n, mid+1, r);
	
	Merge(a, n, l, r);
	
}

int main(){
	
	
	int a[6] = {5, 3, 6, 4, 1, 2};
	
	MergeSort(a, 6, 0, 5);
	
	for(auto i : a)
		cout << i << " ";
	
	return 0;
}