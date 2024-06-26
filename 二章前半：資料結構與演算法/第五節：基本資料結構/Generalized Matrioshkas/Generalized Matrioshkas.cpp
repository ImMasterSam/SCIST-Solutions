#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	string buf;
	
	while(getline(cin, buf)){
		
		int arr[10000] = {0};
		int n = 0;
		
		const char *ptr = buf.c_str();
		int pos;
		
		while(sscanf(ptr, "%d%n", &arr[n], &pos) != EOF){
			
			ptr += pos;
			n++;
			
		}
		
		int stack[10000] = {0};
		int value[10000] = {0};
		int idx = 0;
		bool Matrioshkas = true;
		
		for(int i=0;i<n;i++){
			
			int top = 0;
			if(idx)
				top = stack[idx-1];
				
			//cout << top << " : " << arr[i] << "\n";
				
			if(top == 0)
				stack[idx++] = arr[i];
			
			else{
				
				if(arr[i] < 0){
					
					if(abs(arr[i]) + value[idx-1] < abs(top)){
						
						value[idx-1] += abs(arr[i]);
						stack[idx++] = arr[i];
						
					}
					else{
						Matrioshkas =false;
						break;
					}
					
				}
				else{
					
					if(arr[i] != -top){
						Matrioshkas =false;
						break;
					}
					else{
						
						value[idx-1] = 0;
						idx--;
						
					}
					
				}
				
			}
			
			
		}
		
		if(Matrioshkas && idx == 0)
			cout << ":-) Matrioshka!\n";
		else
			cout << ":-( Try again.\n";
		
		
	}
	
	
	return 0;
}