#include<iostream>
using namespace std;

long long power(long long b, long long p, long long m){
	
	if(p == 0)
		return 1;
	else if (p == 1)
		return b;
		
	long long t = power(b, p/2, m);
	
	int res;
	
	if(p%2)
		res = (t * t * b) % m;
	else
		res = (t * t) % m;
		
	return res;
	
}

int main(){
	
	long long b, p, m;
	
	while(cin >> b >> p >> m){
		
		b %= m;
		
		cout << power(b, p, m) << "\n";
		
	}
	
	return 0;
}