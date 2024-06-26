#include<iostream>
#include<cmath>
using namespace std;

int a[55];

int main(){
	
	int n, ans, avg, t=1;
	cin >> n;
	
	while(n!=0){
		
		int sum = 0;
		ans = 0;
		
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		
		avg = sum/n;
		
		for(int i=0;i<n;i++){
			
			if (a[i]-avg>0)
				ans += a[i]-avg;
			
		}
		
		cout << "Set #" << t << "\n";
		cout << "The minimum number of moves is " << ans << ".\n\n";	
		
		t++;
		cin >> n;
		
	}
	
	return 0;
}