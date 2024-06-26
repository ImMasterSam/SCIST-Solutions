#include<iostream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t, n;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		cin >> n;
		int high = 0, low = 0;
		int pre, now;
		cin >> pre;
		
		for(int i=1;i<n;i++){
			cin >> now;
			if(now-pre > 0)
				high++;
			else if(now-pre < 0)
				low++;
			
			pre = now;
		}
		
		cout << "Case " << time+1 << ": " << high << " " << low << "\n";
		/*if(time!=t-1)
			cout << "\n";*/
		
	}
	
	return 0;
}