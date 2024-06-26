#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
int arr[500005];

void merge(int l, int r){
	
	int temp[r-l+1] = {0};
	
	int mid = (l+r)/2;
	int i = l;
	int j = mid + 1;
	int k;
	
	for(k=0;k<=r-l;k++){
		
		if(i <= mid && (j>r || arr[i]<=arr[j])){
			
			temp[k] = arr[i++];
			
		}
		else{
			
			ans += mid - i + 1;
			
			temp[k] = arr[j++];
			
		}
		
	}
	
	for(k=0;k<=r-l;k++){
		
		arr[k+l] = temp[k];
		
	}
	
}

void solve(int l, int r){
	
	if(l == r)
		return;
	
	int mid = (l+r)/2;
	
	solve(l, mid);
	solve(mid+1, r);
	/*
	int i, j;
	
	for(i = mid + 1, j = l; i<=r; i++){
		
		for(;j<=mid && arr[j]<arr[i];j++);
		
		ans += mid + 1 - j;
		
	}*/
	
	merge(l, r);
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(cin >> n, n){
		
		ans = 0;
		
		for(int i=0;i<n;i++)
			cin >> arr[i];
			
		solve(0, n-1);
		
		cout << ans << "\n";
		
	}
	
	return 0;
}