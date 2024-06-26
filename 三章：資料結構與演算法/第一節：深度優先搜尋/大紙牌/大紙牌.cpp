#include <iostream>
#include <stack>
using namespace std;

stack<int> stk[4];
bool ans = false;

void dfs(int depth){
	
	if(depth == 26){
		
		ans = true;
		return;
		
	}
	
	for(int i=0;i<3 && !ans;i++){
		
		for(int j=i+1;j<4 && !ans;j++){
			
			if(stk[i].empty() || stk[j].empty())
				continue;
			
			int a = stk[i].top();
			int b = stk[j].top();
			
			if(a == b){
				
				stk[i].pop();
				stk[j].pop();
				dfs(depth+1);
				stk[i].push(a);
				stk[j].push(b);
				
			}
			
		}
		
	}
	
}

int main(){
	
	int x;
	
	while(cin >> x){
		
		ans = false;
		
		for(int i=0;i<4;i++){
		
			for(int j=0;j<13;j++){
				
				if(i!=0||j!=0)
					cin >> x;
				
				stk[i].push(x);
				
			}
			
		}
		
		
		dfs(0);
		
		cout << (ans ? "YES\n" : "NO\n");
		
	}
	
	
	
	
	return 0;
}