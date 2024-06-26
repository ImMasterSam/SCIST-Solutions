#include<iostream>
using namespace std;

int ans[14];

bool judge(int n, int k){
	
	int ptr = 0;
	
	for(int i=n*2;i>n;i--){
		
		ptr = (ptr - 1 + k) % i;
		
		if(ptr < n)
			return false;
		
	}
	
	return true;
}

int solve(int k){
	
	int i = k+1;
	
	while(1){
		
		int res = judge(k, i++);
		
		if(res)
			break;
		
	}
	
	return i-1;
	
}

int main(){
	
	int k;
	
	for(int i=1;i<14;i++){
		
		ans[i] = solve(i);
		
	}
	
	while(cin >> k, k){
		
		cout << ans[k] << "\n";
		
	}
	
	return 0;
}