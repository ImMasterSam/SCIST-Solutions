#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, now, pre;
	while(cin >> n){
		
		int a[3005] = {0};
		bool y = true;
		
		for(int i=0;i<n;i++){
			cin >> now;
			if(i==0){
				pre = now;
			}
			else{
				if(abs(now-pre)<3005)
					a[abs(now-pre)]++;
				pre = now;
			}
		}
		
		for(int i=1;i<n;i++){
			if(a[i] == 0)
				y = false;
		}
		
		if(y)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
		
	}
	return 0;
}

