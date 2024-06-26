#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

unordered_map<int, int> m;

int binarysearch(vector<int> &length, int v){
	
	int l = 0, r = length.size()-1;
	int res = -1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(length[mid] <= v){
			
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
	cin >> n;
	
	for(int i=1;i<=n;i++){
		
		int x;
		cin >> x;
		m[i] = x;
		
	}
	
	int temp;
	int arr[n];
	vector<int> length;
	
	while(cin >> temp){
		
		arr[temp-1] = 1;
		length.clear();
		
		for(int i=2;i<=n;i++){
			
			cin >> temp;
			arr[temp-1] = i;
			
		}
			
			
		for(int i=0;i<n;i++){
			
			if(length.empty() || m[arr[i]] > length.back())
				length.push_back(m[arr[i]]);
			else{
				
				int idx = binarysearch(length, m[arr[i]]);
				length[idx+1] = m[arr[i]];
				
			}
			/*
			for(int &i:length)
				cout << i << " ";
			cout << "\n";
			*/
		}
		
		cout << length.size() << "\n";
		
	}
		
	
	return 0;
}
