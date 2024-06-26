#include<iostream>
#include<climits>
using namespace std;

long long a[605];

int days(int dis, int n){
	
	int day = 1;
	int sum_d = 0;
	
	for(int i=0;i<n+1;i++){
		
		if(a[i]>dis)
			return 400;
		
		if(sum_d + a[i] > dis){
			day++;
			sum_d = a[i];
		}
		else
			sum_d += a[i];
		
	}
	
	return day;
	
}

int binary(int k, int n){
	
	unsigned long long l=0, r = LLONG_MAX;
	
	long long ans = -1;
	
	while(l<=r){
		
		long long mid = (l+r)/2;
		
		if(days(mid, n) <= k){
			r = mid-1;
			ans = mid;
		}
		else
			l = mid+1;
		
	}
	
	return ans;
	
}

int main(){
	
	int n, k;
	
	while(cin >> n >> k){
		
		k++;
		
		for(int i=0;i<n+1;i++)
			cin >> a[i];
			
		cout << binary(k, n) << "\n";
		
	}
		
	
	
	return 0;
}