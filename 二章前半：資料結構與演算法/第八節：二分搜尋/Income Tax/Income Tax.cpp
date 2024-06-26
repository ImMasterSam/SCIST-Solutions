#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	long long m, x;
	
	while(cin >> m >> x){
		
		if(m == 0 && x == 0)
			break;
			
		if(x == 100){
			
			cout << "Not found\n";
			continue;
			
		}
		
		long long ans = ceil((double)m/(1-x/100.0))+5;
		
		while(ans*(100-x) >= (m-1)*100){
			
			ans--;
			
		}
			
		if(ans <= m-1)
			cout << "Not found\n";
		else
			cout << ans << "\n";
			
		
	}
		
	return 0;
}