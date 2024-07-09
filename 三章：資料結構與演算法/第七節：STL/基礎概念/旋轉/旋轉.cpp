#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
		
	reverse(arr, arr+n);
	
	for(int i=0;i<n;i++)
		cout << arr[i] << "\n";
	
	return 0;
}
