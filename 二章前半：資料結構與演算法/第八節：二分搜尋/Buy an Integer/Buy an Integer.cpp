#include<iostream>
#include<climits>
using namespace std;

int d(long long n){
	
	int count = 0;
	
	while(n){
		
		count++;
		n /= 10;
		
	}
	
	return count;
	
}

long long BinarySearch(long long a, long long b, long long x){
	
	long long l=0, r=1e9;
	long long ans = -1;
	
	while(l<=r){
		
		long long mid = (l+r)/2;
		
		if(a*mid + b*d(mid) <= x){
			l = mid+1;
			ans = mid;
		}
		else
			r = mid-1;
		
	}
	
	return ans;
	
}

int main(){
	
	long long a, b, x;
	
	cin >> a >> b >> x;
	
	int res = BinarySearch(a, b, x);
	
	if(res == 0)
		cout << "0\n";
	else
		cout << res << "\n";
	
	
	return 0;
}