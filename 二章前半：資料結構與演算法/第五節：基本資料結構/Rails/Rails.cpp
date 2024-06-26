#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	stack<int> stk;
	
	int n;
	
	while(cin >> n, n){
		
		int in[n] = {0};
		
		while(cin >> in[0], in[0]){
			
			while(stk.size())
				stk.pop();
			
			int in_idx = 0;
			for(int i=1;i<n;i++)
				cin >> in[i];
			
			for(int i=1;i<=n;i++){
				
				stk.push(i);
				
				while(stk.size() && stk.top() == in[in_idx]){
					
					stk.pop();
					in_idx++;
					
				}
				
			}
				
			if(stk.size() == 0)
				cout << "Yes\n";
			else
				cout << "No\n";
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}