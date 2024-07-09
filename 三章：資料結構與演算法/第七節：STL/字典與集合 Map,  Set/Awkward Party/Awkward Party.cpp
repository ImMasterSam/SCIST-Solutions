#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	map<int, int> last;
	int MIN = n;
	for(int i=0;i<n;i++){
		
		int x;
		cin >> x;
		
		if(last[x] == 0){
			
			last[x] = i + 1;
			continue;
			
		}
		
		MIN = min(MIN, i + 1 - last[x]);
		
	}
	
	cout << MIN << "\n";
	
	return 0;
}
