#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int a[n]={1}, x;
	
	for(int i=0;i<n-1;i++){
		cin >> x;
		a[1+x] = i+2;
	}
	
		
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	
	
	
	return 0;
}