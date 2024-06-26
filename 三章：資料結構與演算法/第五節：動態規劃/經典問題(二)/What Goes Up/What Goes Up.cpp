#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<int> arr;
vector<int> LIS;
vector<int> pre;

int binarysearch(int idx){
	
	int l = 0, r = LIS.size()-1;
	int res = -1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(arr[LIS[mid]] < arr[idx]){
			
			res = mid;
			l = mid + 1;
			
		}
		else
			r = mid - 1;
		
	}
	
	return res;
	
}

void output(int idx){
	
	if(pre[idx] != -1)
		output(pre[idx]);
	
	cout << arr[idx] << "\n";
	
}

int main(){ BOOST

	arr.reserve(500005);
	LIS.reserve(500005);
	
	int n;
	while(cin >> n)
		arr.push_back(n);
		
	pre.assign(arr.size(), -1);
	
	for(int i=0;i<arr.size();i++){
		
		if(LIS.empty())
			LIS.push_back(i);
		else if(arr[i] > arr[LIS.back()]){
			
			pre[i] = LIS.back();
			LIS.push_back(i);
			
		}
		else{
			
			int idx = binarysearch(i);
			LIS[idx+1] = i;
			if(idx != -1)
				pre[i] = LIS[idx];
			
		}
	}
	
	cout << LIS.size() << "\n-\n";
	output(LIS.back());
	
	
	return 0;
}
