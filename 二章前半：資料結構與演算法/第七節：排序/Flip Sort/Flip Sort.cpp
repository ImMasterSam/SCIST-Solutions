#include<iostream>
using namespace std;

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
	
}

int bubblesort(int *a, int n){
	
	int count = 0;
	
	for(int i=0;i<n-1;i++){
		
		for(int j=0;j<n-i-1;j++){
			
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
				count++;
			}
			
		}
		
	}
	
	return count;
	
}

int main(){
	
	int n;
	int a[1005];
	
	
	while(cin >> n){
		
		for(int i=0;i<n;i++)
			cin >> a[i];
		
		cout << "Minimum exchange operations : " << bubblesort(a, n) << "\n";
		
		/*for(int i=0;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";*/
		
	}
	
	return 0;
}