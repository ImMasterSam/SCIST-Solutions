#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[20001] = {0};

int DC(int left, int right, int target){
	
	if(left == right)
		return (arr[left] > target) ? 1 : 0;
	
	int res = 0;
	int mid = (left + right)/2;
	
	res += DC(left, mid, target);
	res += DC(mid + 1, right, target);
	
	int i, j;
	
	for(i = left, j = mid+1; j<=right;j++){
		
		while(i<=mid && arr[j] - arr[i] > target) i++;
		
		res += i - left;
		
	}
	
	return res;
}

int main(){
	
	while(cin >> n >> k){
		
		if(n==0 && k == 0)
			break;
			
		for(int i=1, x;i<=n;i++){
			
			cin >> x;
			
			arr[i] = arr[i-1] + x;
			
		}
		
		int l = 0, r = INT_MAX-1;
		int ans = -1;
		
		while(l <= r){
			
			int mid = (l+r)/2;
			int res = DC(1, n, mid);
			
			//cout << mid << " : " << res << "\n";
			
			if(res <= k-1){
				
				ans = mid;
				r = mid - 1;
				
			}
			
			else
				l = mid + 1;
			
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}