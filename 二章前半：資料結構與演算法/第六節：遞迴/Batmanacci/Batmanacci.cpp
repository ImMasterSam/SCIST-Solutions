#include<iostream>
using namespace std;

long long fib[100010];

char solve(long long n, long long k){
	
	if(n == 1)
		return 'N';
	else if (n == 2)
		return 'A';
	else{
		
		long long temp = fib[n-2];
		
		if(k<=temp)
			return solve(n-2, k);
		else
			return solve(n-1, k-temp);
		
	}
	
}


int main(){
	
	long long n, k;
	
	cin >> n >> k;
	
	fib[1] = 1;fib[2] = 1;
	for(int i=3;i<=100005;i++){
		
		fib[i] = fib[i-1] + fib[i-2];
		
		if(fib[i] > 1e18)
			fib[i] = 1e18 + 1;
		
	}
	
	cout << solve(n, k);
	
	return 0;
}