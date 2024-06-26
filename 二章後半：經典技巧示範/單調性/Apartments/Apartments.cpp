#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	long long n, m, k;
	cin >> n >> m >> k;
	
	long long a[n] = {0}, b[m] = {0};
	
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<m;i++)
		cin >> b[i];
		
	sort(a, a+n);
	sort(b, b+m);
	
	long long i=0, j=0;
	
	int ans = 0;
	
	while(i<n && j<m){
		
		if(abs(a[i]-b[j]) <= k){
			
			i++;
			j++;
			ans++;
			
		}
		else{
			
			if(a[i] - b[j] > k)
				j++;
			else
				i++;
			
		}
		
	}
	
	cout << ans;
	
	
	return 0;
}