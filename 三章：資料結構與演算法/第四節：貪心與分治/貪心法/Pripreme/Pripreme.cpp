#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	long long MAX = 0, time = 0;
	long long temp;
	
	while(n--){
		
		cin >> temp;
		MAX = max(MAX, temp);
		
		time += temp;
		
	}
	
	cout << max(time, MAX*2);
	
	
	return 0;
}