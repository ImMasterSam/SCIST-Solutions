#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

bool cmp(const int &a, const int &b){
	
	if(a%m != b%m){
		
		return a%m < b%m;
		
	}
	
	int ac = (a&1);
	int bc = (b&1);
	
	if(ac != bc){
		
		return ac > bc;
		
	}
	
	if(ac && bc){
		
		return a > b;
		
	}
	
	else{
		
		return a < b;
		
	}
	
	return false;
	
}

int main(){
	
	while(cin >> n >> m){
		
		cout << n << " " << m << "\n";
		
		if(n==0 && m==0)
			break;
		
		int a[n];
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		sort(a, a+n, cmp);
		
		for(int i=0;i<n;i++)
			cout << a[i] << "\n";
		
	}
	
	
	return 0;
}