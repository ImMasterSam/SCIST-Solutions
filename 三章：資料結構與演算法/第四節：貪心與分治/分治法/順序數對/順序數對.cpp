#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int arr[1000000];

void DC(int left, int right){
	
	if(right - left <= 1)
		return;
		
	int mid = (left + right)/2;
	
	DC(left, mid);
	DC(mid+1, right);
	
	int i, j, k;
	
	for(i=left, j = mid+1, k = left+1;i<=mid;i++){
		
		
		
	} 
	
}

int main(){
	
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	cout << ans << "\n";
	
	return 0;
}