#include<iostream>
using namespace std;

int main(){
	
	int n;
	int count = 1;
	
	while(cin >> n){
		
		int a[n];
		
		long long max = 0;
		
		for(int i=0;i<n;i++)
			cin >> a[i];
		
		for(int i=0;i<n;i++){
			
			long long temp = 1;
			
			for(int j=i;j<n;j++){
				
				temp *= a[j];
				
				if(temp > max)
					max = temp;
				
			}
			
		}
		
		cout << "Case #" << count << ": The maximum product is " << max << ".\n\n";
		count++;
		
	}
	
	return 0;
}