#include<iostream>
using namespace std;

int main(){
	
	int l;
	int r=0, s=0;
	string a, b;
	
	cin >> l >> a >> b;
	
	int used_k[l] = {0}, used_g[l] = {0};
	
	for(int i=0;i<l;i++){
			
		if(!used_k[i] && !used_g[i]){
			
			if(a[i] == b[i]){
				
				r++;	
				used_k[i] = 1;
				used_g[i] = 1;
				
			}
			
		}
		
	}
	
	for(int i=0;i<l;i++){
		
		for(int j=0;j<l;j++){
			
			if(!used_k[i] && !used_g[j]){
				
				if(a[i] == b[j] && i != j){
					
					s++;	
					used_k[i] = 1;
					used_g[j] = 1;
					break;
					
				}
				
			}
			
		}
		
	}
	
	cout << r << " " << s;
	
	return 0;
}