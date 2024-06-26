#include <iostream>
using namespace std;

bool used[15] = {0};
long long a[15] = {0};

int k;

void dfs(int depth, int start){
	
	if(depth == 6){
		
		bool first = true;
		
		for(int i=0;i<k;i++){
			
			if(used[i]){
				
				if(!first)
					cout << " ";
				cout << a[i];
				first = false;
				
			}
			
		}
		
		cout << "\n";
		
	}
	
	for(int i=start;i<k;i++){
		
		if(!used[i]){
			
			used[i] = true;
			dfs(depth+1, i+1);
			used[i] = false;
			
		}
		
	}
	
}

int main(){
	
	bool first = true;
	
	while(cin >> k, k){
		
		if(!first)
			cout << "\n";
		
		for(int i=0;i<k;i++)
			cin >> a[i];
			
		dfs(0, 0);
		
		first = false;
		
	}
	
	return 0;
}