#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	string buffer;
	string input;
	
	long long coe[1024];
	
	while(getline(cin, buffer)){
		
		int n=0;
		
		const char *ptr = buffer.c_str();
		int pos;
		
		while(sscanf(ptr, "%lld%n", &coe[n], &pos) == 1){
			
			n++;
			ptr += pos;
			
		}
		
		getline(cin, input);
		
		long long x;
		ptr = input.c_str();
		
		bool one = false;
		
		while(sscanf(ptr, "%lld%n", &x, &pos) == 1){
			
			ptr += pos;
			
			long long ans = 0, temp = 1;
			
			for(int i=n-1;i>=0;i--){
				
				ans += coe[i]*temp;
				temp *= x;
				
			}
			
			if(one)
				cout << " ";
			
			cout << ans;
			one = true;
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}