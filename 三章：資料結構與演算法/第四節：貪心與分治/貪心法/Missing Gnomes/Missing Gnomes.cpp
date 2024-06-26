#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, m;
	cin >> n >> m;
	
	bool used[n+1] = {0};
	int arr[m];
	
	for(int i=0;i<m;i++){
		
		cin >> arr[i];
		used[arr[i]] = true;
		
	}
	
	int idx = 1;
	
	while(used[idx] && idx <= n) idx++;
	
	for(int i=0;i<m;i++){
		
		while(arr[i] > idx && idx <= n){
			
			cout << idx << "\n";
			used[idx] = true;
			
			while(used[idx] && idx <= n) idx++;
			
		}
		
		cout << arr[i] << "\n";
		
	}
	
	while(idx <= n){
		
		cout << idx << "\n";
		idx++;
		
	}
	
	
	return 0;
}