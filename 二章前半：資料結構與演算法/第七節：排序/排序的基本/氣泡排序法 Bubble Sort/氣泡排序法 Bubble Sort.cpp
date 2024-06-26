#include<iostream>
using namespace std;

void swap(int &a, int &b){
	
	int t = a;
	a = b;
	b = t;
	
}

void BubbleSort(int a[], int n){
	
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-i-1;j++){
			
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
			
		}
		
	}
	
}

int main(){
	
	int a[5] = {5, 3, 4, 1, 2};
	
	BubbleSort(a, 5);
	
	for(auto i : a)
		cout << i << " ";
	
	
	return 0;
}