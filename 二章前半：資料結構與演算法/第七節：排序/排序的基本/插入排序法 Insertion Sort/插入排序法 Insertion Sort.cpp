#include<iostream>
using namespace std;

void swap(int &a, int &b){
	
	int t = a;
	a = b;
	b = t;
	
}

void InsertionSort(int a[], int n){
	
	for(int i=0;i<n;i++){
		
		int temp = a[i];
		int j;
		
		for(j=i-1;j>=0&&a[j]>temp;j--)
			a[j+1] = a[j];
			
		a[j+1] = temp;
		
	}
	
}

int main(){
	
	int a[5] = {5, 3, 4, 1, 2};
	
	InsertionSort(a, 5);
	
	for(auto i : a)
		cout << i << " ";
	
	
	return 0;
}