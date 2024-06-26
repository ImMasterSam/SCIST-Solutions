#include <bits/stdc++.h>
using namespace std;

void clear(stack<int> &stk){
	
	stack<int> empty;
	swap(stk, empty);
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	stack<int> stk;
	
	while(t--){
		
		clear(stk);
		
		int n;
		cin >> n;
		
		if(n == 1)
			cout << "1\n";
		else if(n == 0)
			cout << "0\n";
			
		else{
			
			for(int i=9;i>=2;i--){
				
				while(n % i == 0){
					
					stk.push(i);
					n /= i;
					
				}
				
			}
			
			if(n > 1)
				cout << "-1\n";
			
			else{
				
				while(stk.size()){
					
					cout << stk.top();
					stk.pop();
					
				}
				
				cout << "\n";
				
			}
			
		}
		
	}
	
	return 0;
}