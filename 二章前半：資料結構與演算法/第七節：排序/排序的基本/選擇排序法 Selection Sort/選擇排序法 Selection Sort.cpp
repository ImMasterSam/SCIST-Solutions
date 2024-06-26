#include<iostream>
using namespace std;

void swap(int &a, int &b){
	
	int t = a;
	a = b;
	b = t;
	
}

void SelectionSort(int a[], int n){
	
	for(int i=0;i<n-1;i++){
		
		int min = i;
		
		for(int j=i;j<n;j++){
			
			if(a[j] < a[min])
				min = j;
			
		}
		
		swap(a[i], a[min]);
		
	}
	
}

int main(){
	
	int a[5] = {5, 3, 4, 1, 2};
	
	SelectionSort(a, 5);
	
	for(auto i : a)
		cout << i << " ";
	
	
	return 0;
}