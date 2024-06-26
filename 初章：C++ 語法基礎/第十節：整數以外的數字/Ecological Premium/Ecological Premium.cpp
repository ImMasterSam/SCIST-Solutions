#include<iostream>
using namespace std;

int main(){
	
	long long  n, f, a, b, c;
	cin >> n;
	
	for(int t=0;t<n;t++){
		cin >> f;
		
		long long sum = 0;
		
		for(int i=0;i<f;i++){
			cin >> a >> b >> c;
			sum += a*c;
		}
		
		cout << sum << '\n';
	}
		
	return 0;
}