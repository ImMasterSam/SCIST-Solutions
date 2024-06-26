#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int n, t, x;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	sort(a, a+n);
		
	cin >> t;
	
	for(int times=0;times<t;times++){
		
		cin >> x;
		
		int l=0, r=n-1;
		
		int ans = -1;
		
		while(l<=r){
			
			int mid = (l+r)/2;
			
			if(a[mid] == x){
				ans = mid;
				break;
			}
			else if(a[mid] <= x){
				l = mid +1;
				ans = mid;
			}
			else
				r = mid - 1;
			
		}
		
		if(a[ans] == x)
			cout << a[ans] << "\n";
		else{
			
			if(ans < 0){
				cout << "no ";
				cout << a[ans+1];
			}
			else if (ans == n-1){
				cout << a[ans];
				cout << " no";
			}
			
			else{
				cout << a[ans] << " " << a[ans+1];
			}
			
			cout << "\n";
			
		}
		
	}
		
	return 0;
}