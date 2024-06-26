#include <iostream>
using namespace std;

int main(){
	int n, a, ans;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a>10)
			ans += a-10;
	}
	cout << ans << "\n";
	
	return 0;
}

