#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		int A[n], B[n];
		int a[n], b[n];
		
		int x;
		
		for(int i=0;i<n;i++){
			
			cin >> x;
			A[i] = x;
			a[i] = x;
			
		}
			
		for(int i=0;i<n;i++){
			
			cin >> x;
			B[i] = x;
			b[i] = x;
			
		}
			
		sort(a, a+n);
		sort(b, b+n);
		
		map<int, int> m;
		
		for(int i=0;i<n;i++){
			
			m[a[i]] = b[i];
			
		}
		
		for(int i=0;i<n;i++){
			
			cout << m[A[i]] << "\n";
			
		}
		
		cout << "\n";
		
	}
	
	
	return 0;
}