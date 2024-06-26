#include <iostream>
using namespace std;

int main(){
	int n, a, b, ans;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		ans = 1;
		for(int j=0;j<b;j++)
			ans *= a;
		cout << ans << "\n";
	}
	
	return 0;
}

