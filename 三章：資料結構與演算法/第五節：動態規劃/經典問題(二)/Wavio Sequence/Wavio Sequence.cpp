#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<int> LIS;
vector<int> LISR;
vector<int> arr;
vector<int> nums1;
vector<int> nums2;

// 
// nums 用來紀錄此數字位在 LIS 或 LISR 的第幾階(深度)
// 
// nums1 代表 LIS  我往前算最多可以提供的遞增子序列
// nums2 代表 LISR 往後算最多可以提供的遞減子序列
// 

int binarysearch(vector<int> &dp, int idx){
	
	int l = 0, r = dp.size()-1;
	int res = -1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(arr[dp[mid]] < arr[idx]){
			
			res = mid;
			l = mid + 1;
			
		}
		else
			r = mid - 1;
		
	}
	
	return res;
	
}

int main(){ BOOST

	int n;
	
	while(cin >> n){
		
		LIS.clear();
		LISR.clear();
		
		arr.assign(n, 0);
		nums1.assign(n, 0);
		nums2.assign(n, 0);
		for(int i=0;i<n;i++)
			cin >> arr[i];
		
		// LIS
		for(int i=0;i<n;i++){
			
			if(LIS.empty()){
				
				LIS.push_back(i);
				nums1[i] = 0;
				
			}
				
			else if(arr[i] > arr[LIS.back()]){
				
				nums1[i] = LIS.size();
				LIS.push_back(i);
				
			}
			else{
				
				int idx = binarysearch(LIS, i);
				LIS[idx+1] = i;
				nums1[i] = idx+1;
				
			}
			
		}
		// Reverse LIS
		for(int i=n-1;i>=0;i--){
			
			if(LISR.empty()){
				
				LISR.push_back(i);
				nums2[i] = 0;
				
			}
				
			else if(arr[i] > arr[LISR.back()]){
				
				nums2[i] = LISR.size();
				LISR.push_back(i);
				
			}
			else{
				
				int idx = binarysearch(LISR, i);
				LISR[idx+1] = i;
				nums2[i] = idx+1;
				
			}
			
		}
		
		int ans = 0;
		for(int i=0;i<n;i++){
			
			ans = max(ans, min(nums1[i], nums2[i])*2 + 1);
			
		}
		
		cout << ans << "\n";
		/*
		cout << "LIS: ";
		for(int i=0;i<n;i++)
			cout << nums1[i] << " ";
		cout << "\n";
		
		cout << "LISR: ";
		for(int i=0;i<n;i++)
			cout << nums2[i] << " ";
		cout << "\n";
		*/
	}
	
	return 0;
}
