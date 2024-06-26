#include<iostream>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n){
		
		while(n != 0){
			
			int x;
			
			int h[n] = {0}, l[n] = {0};
			
			for(int i=0;i<n;i++){
				
				for(int j=0;j<n;j++){
					
					cin >> x;
					
					if(x){
						
						h[j]++;
						l[i]++;
						
					}
					
				}
				
			}
			
			int odd_h = -1, odd_l = -1;
			
			int cor = 0;
			
			for(int i=0;i<n;i++){
				
				if(h[i]%2 == 1){
					
					if(odd_h != -1)
						cor = 1;
					else
						odd_h = i+1;
					
				}
				
				if(l[i]%2 == 1){
					
					if(odd_l != -1)
						cor = 1;
					else
						odd_l = i+1;
					
				}
				
			}
			
			if(odd_h == -1 && odd_l == -1)
				cout << "OK\n";
			else if(cor)
				cout << "Corrupt\n";
			else
				cout << "Change bit (" << odd_l << "," << odd_h << ")\n";
			
			
			cin >> n;
		}
		
	}
	
	return 0;
}