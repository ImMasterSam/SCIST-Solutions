#include<iostream>
using namespace std;

int d[370] = {0};

int main(){
	
	int n, a, b, ans = 0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		cin >> a >> b;
		
		for(int j=a;j<=b;j++)
			d[j] = 1;
		
	}
	
	for(int i=0;i<370;i++){
		
		if(d[i]==1)
			ans++;
		
	}
	
	cout << ans;
	
	return 0;
}