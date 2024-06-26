#include<iostream>
using namespace std;

int primes[100000] = {0};
int n_p = 0;

bool isprime(int n){
	
	if(n == 1)
		return false;
	
	if(n%2 == 0){
		
		if(n == 2)
			return true;
		else
			return false;
		
	}
	
	if(n%3 == 0){
		
		if(n == 3)
			return true;
		else
			return false;
		
	}
	
	if(n%5 == 0){
		
		if(n == 5)
			return true;
		else
			return false;
		
	}
	
	for(int i=6;i*i<=n;i+=6){
		
		if(n%(i-1) == 0 || n%(i+1) == 0)
			return false;
		
	}
	
	return true;
}

int digit(int n){
	
	int sum = 0;
	
	while(n){
		
		sum += n%10;
		n /= 10;
		
	}
	
	return sum;
}

int bin(int val){
	
	int l = 0, r = n_p;
	
	int ans = -1;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(primes[mid] < val){
			
			l = mid + 1;
			ans = mid;
			
		}
		else
			r = mid - 1;
		
	}
	
	return ans;
	
}

int main(){
	
	for(int i=2;i<1000000;i++){
		
		if(isprime(i) && isprime(digit(i))){
			//cout << i << ", ";
			primes[n_p++] = i;
		}
		
	}
	
	//cout << "\n";
	
	int t;
	cin >> t;
	
	for(int i=0;i<t;i++){
		
		int a, b;
		cin >> a >> b;
		
		int idx_1 = bin(a);
		int idx_2 = bin(b);
		/*
		cout << primes[idx_1] << " " << primes[idx_2] << "\n";
		cout << idx_1 << " " << idx_2 << "\n";*/
		
		cout << idx_2 - idx_1 << "\n";
		
	}
	
	
	return 0;
}