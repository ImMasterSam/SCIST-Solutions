#include<iostream>
using namespace std;

int main(){
	
	int q;
	cin >> q;
	
	int Fib[1000] = {0};
	
	for(int que=0;que<q;que++){
		
		int k;
		cin >> k;
		
		Fib[0] = 1;Fib[1] = 1;
		
		int count[k] = {0};
		
		int i = 2;
		
		while(1){
			
			Fib[i] = (Fib[i-1] + Fib[i-2])%k;
			
			if(count[Fib[i]] != 0){
				
				cout << count[Fib[i]] << "\n";
				break;
				
			}
			else{
				
				count[Fib[i]] = i;
				
			}
			
			//cout << i << ": " << Fib[i-1] << " " << Fib[i] << "\n";
				
			i++;
			
		}
		
	}
	
	return 0;
}