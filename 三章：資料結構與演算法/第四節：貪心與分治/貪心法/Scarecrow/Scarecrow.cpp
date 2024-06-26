#include <bits/stdc++.h>
using namespace std;

char a[100] = {0};
bool stand[100] = {0};

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int n;
		cin >> n;
		
		for(int i=0;i<n;i++){
			
			cin >> a[i];
			stand[i] = false;
			
		}
		
		int scare = 0;
		
		for(int i=0;i<n;i++){
			
			if(a[i] == '#')
				continue;
			
			if(i == 0){
				
				stand[i+1] = true;
				scare++;
				
			}
			
			else if(i == n-1){
				
				if(!(stand[i-1] || stand[i]))
					scare++;
				
			}
			else{
				
				if(stand[i-1] || stand[i] || stand[i+1])
					continue;
				
				stand[i+1] = true;
				scare++;
				
			}
			
		}
		
		cout << "Case " << time+1 << ": " << scare << "\n"; 
		
	}
	
	return 0;
}