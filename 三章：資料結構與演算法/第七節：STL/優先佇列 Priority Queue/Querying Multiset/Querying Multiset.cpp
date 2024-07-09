#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> a, b;

int main(){ BOOST

	int q;
	cin >> q;
	
	long long total = 0;
	
	for(int query=0;query<q;query++){
		
		int p, x;
		cin >> p;
		
		switch(p){
			
			case 1:
				cin >> x;
				a.push(x - total);
				break;
				
			case 2:
				cin >> x;
				total += x;
				break;
			
			case 3:
				cout << a.top()+total << "\n";
				a.pop();
				break;
		}
		
	}
	
	return 0;
}
