#include<iostream>
#include<cmath>
using namespace std;

int pth(long long n){
	
	int p = 1;
	
	int sq = sqrt(abs(n));
	
	for(int i=-sq;i<=sq;i++){
		
		if(i == 0 || i == -1 || i == 1) continue;
		
		long long pro = i;
		int count = 1;
		
		while(pro <= abs(n) && pro >= -abs(n)){
			
			if(pro == n){
				
				if(count > p)
					p = count;
					
				break;
				
			}
			
			pro *= i;
			count++;
			
		}		
		
	}
	
	return p;
	
}

int main(){
	
	long long n;
	
	while(cin >> n){
		
		if(n == 0)
			break;
		
		cout << pth(n) << "\n";
		
	}
	
	return 0;
}