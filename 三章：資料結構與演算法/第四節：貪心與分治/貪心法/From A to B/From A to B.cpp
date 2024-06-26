#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	
	int step = 0;
	
	while(a != b){
		
		if(!(a & 1) && a > b)
			a /= 2;
		else
			a++;
			
		step++;
		
	}
	
	cout << step;
	
	return 0;
}