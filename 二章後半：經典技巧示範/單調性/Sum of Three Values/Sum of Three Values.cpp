#include <iostream>
#include <algorithm>
using namespace std;

int arr[5005];
int idx[5005];
int n, x;

bool cmp(const int &a, const int &b){
	
	return arr[a] < arr[b];
	
}

int main(){
	
	cin >> n >> x;
	
	for(int i=0;i<n;i++){
		
		cin >> arr[i];
		idx[i] = i;
				
	}
	
	sort(idx, idx+n, cmp);
	
	bool found = false;
	int i, l, r;
	int ans[3] = {0};
	
	for(i=0;i<n&&!found;i++){
		
		int target = x - arr[idx[i]];
		
		for(l=0, r=n-1;l<n&&!found;l++){
			
			for(;r>l && arr[idx[l]] + arr[idx[r]] > target;r--);
			
			if(!(r==l || l==i || i == r) && arr[idx[l]] + arr[idx[r]] == target){
				
				ans[0] = idx[i];
				ans[1] = idx[l];
				ans[2] = idx[r];
				found = true;
				break;
				
				
			}
			
		}
		
	}
	
	sort(ans, ans+3);
	
	if(found)
		cout << ans[0]+1 << " " << ans[1]+1 << " " << ans[2]+1;
	else
		cout << "IMPOSSIBLE";
	
	
	return 0;
}