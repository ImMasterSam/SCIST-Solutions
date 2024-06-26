#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

#define f first
#define s second

vector<pair<int, int>> points;
vector<int> dp;

int binarysearch(int y){
	
	int l = 0, r = dp.size();
	int res = -1;
	
	while(l <= r){
		
		int mid = (l + r)/2;
		
		if(dp[mid] <= y){
			
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
	
	for(int i=0;i<n;i++){
		
		int a, b;
		cin >> a >> b;
		
		points.emplace_back(a, b);
		
	}
	
	sort(points.begin(), points.end());
	dp.push_back(points[0].s);
	
	for(int i=1;i<n;i++){
		
		if(dp.empty() || dp.back() <= points[i].s)
			dp.push_back(points[i].s);
			
		else{
			int idx = binarysearch(points[i].s);
			dp[idx+1] = points[i].s;
		}
			
		
	}
	
	cout << dp.size() << "\n";
	
	return 0;
}
