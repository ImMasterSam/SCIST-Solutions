#include<iostream>
using namespace std;

int main(){
	
	int a, b;
	
	while(cin >> a >> b){
		
		if(a==0 && b==0)
			break;
			
		int bucket[1000] = {0};
		int remain[1000] = {0};
		int b_idx = 0;
		
		//cout << "::" << a << " " << b << "\n";
		
		while(1){
			
			if(a == 0){
				
				cout << ".";
				for(int i=0;i<b_idx;i++){
					
					if(i && i%50 == 49)
							cout << "\n";
					
					cout << bucket[i];
					
				}
				cout << "\nThis expansion terminates.\n\n";
				break;
				
			}
			
			else{
				
				remain[a] = b_idx+1;
				a *= 10;
				bucket[b_idx++] = a/b;
				a = a%b;
				
				if(remain[a] != 0){
					
					cout << ".";
					for(int i=0;i<b_idx;i++){
						
						if(i && i%50 == 49)
							cout << "\n";
						
						cout << bucket[i];
						
					}
					
					cout << "\nThe last " << b_idx - remain[a]+1 << " digits repeat forever.\n\n";
					break;
					
				}
				
			}
			
		}
		
	}
	
	return 0;
}