#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n, m;
	cin >> n >> m;
	
	vector<int> A(n);
	vector<int> B(m);
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	for(int i=0;i<m;i++)
		cin >> B[i];
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	int MIN = INT_MAX;
	
	for(int i=0;i<n;i++){
		
		auto it = lower_bound(B.begin(), B.end(), A[i]);
		
		if(it != B.end())
			MIN = min(MIN, abs(A[i] - *it));
		if(it != B.begin())
			MIN = min(MIN, abs(A[i] - *(it-1)));
		
	}
	
	cout << MIN << "\n";
	
	return 0;
}
