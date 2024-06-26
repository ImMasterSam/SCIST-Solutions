#include<iostream>
using namespace std;

int main(){
	
	int n, r;
	
	while(cin >> n >> r){
		
		int flag[10005] = {0};
		
		for(int i=0;i<r;i++){
			
			int x;
			cin >> x;
			
			flag[x] = 1;
			
		}
		
		if(n == r)
			cout << "*";
		
		else{
			
			for(int i=1;i<=n;i++){
				
				if(!flag[i])
					cout << i << " ";
				
			}
			
		}
		
		cout << "\n";
		
		
	}
	
	
	return 0;
}