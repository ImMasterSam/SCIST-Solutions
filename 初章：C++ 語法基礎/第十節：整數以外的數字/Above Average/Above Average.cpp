#include<iostream>
#include<iomanip>
using namespace std;

int a[1005];

int main(){
	
	int t, n;
	cin >> t;
	
	for(int time=0;time<t;time++){
		cin >> n;
		int sum = 0, count = 0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			sum += a[i];
		}
		
		for(int i=0;i<n;i++){
			if(a[i]>sum/(double)n)
				count++;
		}
		
		cout << fixed << setprecision(3) << 100*count/(double)n << "%\n";
		
	}
		
	return 0;
}