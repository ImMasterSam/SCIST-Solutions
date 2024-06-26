#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, e;
	cin >> n >> e;
	
	long long villager[n+1] = {0};
	int song = 0;
	
	for(int i=0;i<e;i++){
		
		int k;
		cin >> k;
		
		bool bard = false;
		int join[k] = {0};
		
		for(int j=0;j<k;j++){
			
			cin >> join[j];
			
			if(join[j] == 1)
				bard = true;
			
		}
		
		if(bard){
			
			for(int j=0;j<k;j++){
				
				villager[join[j]] |= ((long long)1 << song);
				
			}
			
			song++;
			
		}
		
		else{
			
			long long temp = 0;
			
			for(int j=0;j<k;j++){
				
				temp |= villager[join[j]];
				
			}
			
			for(int j=0;j<k;j++){
				
				villager[join[j]] = temp;
				
			}
			
		}
		
	}
	
	long long all = ((long long)1<<song)-1;
	
	for(int i=1;i<=n;i++){
		
		if(villager[i] == all)
			cout << i << "\n";
		
	}
	
	
	return 0;
}