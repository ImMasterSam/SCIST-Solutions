#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long long a[50005];
int n, k;

bool check(long long m){
	
	int count = 1;
	long long right_range = a[0] + m;
	
	for(int i=0;i<n;i++){
		
		if(a[i] <= right_range)
			continue;
			
		else{
			
			count++;
			right_range = a[i] + m;
			
		}
		
	}
	
	
	return count <= k;
	
	
}


long long BinarySearch(){
	
	long long l = 0, r = LLONG_MAX-1;
	
	long long ans = -1;
	
	while(l<=r){
		
		if(l == r)
			break;
		
		long long mid = (l+r)/2;
		
		if(check(mid)){
			r = mid;
			ans = mid;
		}
		else
			l = mid + 1;
		
	}
	
	return ans;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	cout << BinarySearch();
	
	
	return 0;
}