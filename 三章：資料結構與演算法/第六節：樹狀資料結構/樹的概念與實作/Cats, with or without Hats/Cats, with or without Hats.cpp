#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	long long n, m;
	
	while(cin >> n >> m, n){
		
		long long temp = n * m - 1;
		cout << n << " " << m << " ";
		
		if(n == 1){
			
			if(m == 1)
				cout << "Multiple\n";
			else
				cout << "Impossible\n";
			
			continue;
			
		}
		if(temp % (n-1) == 0)
			cout << temp / (n-1) << "\n";
		else
			cout << "Impossible\n";
		
	}
	
	return 0;
}
