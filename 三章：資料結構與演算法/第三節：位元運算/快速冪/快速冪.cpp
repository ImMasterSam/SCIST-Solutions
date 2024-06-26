#include <iostream>
using namespace std;

int pow(int a, int b){
	
	int ans = 1;
	
	for(int t=b, i=a; t ; t>>=1, i*=i){
		
		if(t&1)
			ans *= i;
		
	}
	
	return ans;
}

int main(){
	
	cout << pow(2, 11);
	
	return 0;
}