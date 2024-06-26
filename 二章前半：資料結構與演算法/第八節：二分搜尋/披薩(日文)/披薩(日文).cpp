#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	
	long long d, n, m;
	cin >> d >> n >> m;
	
	int store[n+1] = {0};
	int order[m] = {0};
	
	for(int i=1;i<n;i++)
		cin >> store[i];
	
	store[n] = d;
	
	sort(store, store+n+1);
	/*
	for(int i=0;i<n+1;i++)
		cout << store[i] << " ";
	cout << "\n";*/
	
	for(int i=0;i<m;i++)
		cin >> order[i];
		
	long long ans = 0;
	
	for(int i=0;i<m;i++){
		
		int l = 0, r = n;
		int res = -1;
		
		while(l<=r){
			
			int mid = (l+r)/2;
			
			if(store[mid] >= order[i]){
				
				r = mid - 1;
				res = mid;
				
			}
			else
				l = mid + 1;
			
		}
		
		//cout << res << "\n";
		
		long long temp = abs(store[res] - order[i]);
		
		if(res){
			
			if(abs(store[res-1] - order[i]) < temp)
				temp = abs(store[res-1] - order[i]);
			
		}
		
		ans += temp;
		
	}
	
	cout << ans << "\n";
	
	
	return 0;
}