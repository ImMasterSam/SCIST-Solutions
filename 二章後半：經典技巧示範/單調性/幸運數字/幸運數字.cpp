#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second

bool cmp(const pair<int, long long> &a, const pair<int, long long> &b){
	
	return a.s < b.s;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, long long> a[n];
	long long S[n+1] = {0};
	
	for(int i=0;i<n;i++){
		
		int x;
		cin >> x;
		a[i] = make_pair(i, x);
		S[i+1] = S[i] + x;
		
	}
	
	sort(a, a+n, cmp);
	
	int l=0, r=n-1;
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		
		if(a[i].f <= r && a[i].f >= l){
			
			ans = a[i].s;
			
			long long left = S[a[i].f] - S[l];
			long long right = S[r+1] - S[a[i].f+1];
			
			//cout << left << " == " << right << "\n";
			
			if(left > right)
				r = a[i].f - 1;
			
			else
				l = a[i].f + 1;
				
			//cout << l << " : " << r << "\n";
			
			if(l == r){
				
				ans = S[r+1] - S[l];
				break;
				
			}
			
		}
		
	}
	
	cout << ans << "\n";
	
	
	return 0;
}