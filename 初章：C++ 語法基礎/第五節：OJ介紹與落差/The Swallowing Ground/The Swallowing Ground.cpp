#include <iostream>
using namespace std;

int main(){
	long long t, w, n , s, g_pre, g_now;
	bool nogap = true;
	cin >> t;
	
	for(int i=0;i<n;i++){
		cin >> w;
		nogap = true;
		
		cin >> n >> s;
		g_pre = n - s;
		
		for(int j=0;j<w-1;j++){
			cin >> n >> s;
			g_now = n - s;
			if(g_now != g_pre){
				nogap = false;
				break;
			}
		}
		
		if(nogap)
			cout << "yes\n\n";
		else
			cout << "no\n\n";
		
	}
	
	return 0;
}

