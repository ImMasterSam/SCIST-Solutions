#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

string s;
vector<int> dp;

int binarysearch(int y){
	
	int l = 0, r = dp.size();
	int res = -1;
	
	while(l <= r){
		
		int mid = (l + r)/2;
		
		if(s[dp[mid]] < s[y]){
			
			res = mid;
			l = mid + 1;
			
		}
		else
			r = mid - 1;
		
		
	}
	
	return res;
	
}

int main(){ BOOST

	cin >> s;
	
	for(int i=0;i<s.size();i++){
		
		if(dp.empty() || s[i] > s[dp.back()])
			dp.push_back(i);
		else{
			
			int idx = binarysearch(i);
			dp[idx+1] = i;
			
		}
		
	}
	
	cout << 26 - dp.size() << "\n";
	
	
	return 0;
}
