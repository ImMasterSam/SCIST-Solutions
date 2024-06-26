#include <iostream>
using namespace std;

int main(){
	int n, e, ans=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> e;
		if(e<0)
		 ans += -e;
	}
	cout << ans << "\n";
	
	return 0;
}

