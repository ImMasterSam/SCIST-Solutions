#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, d;
	string num;
	
	while(cin >> n >> d, (n||d)){
		
		stack<char> stk;
		int del = 0;
		cin >> num;
		
		for(int i=0;i<n;i++){
			
			while(stk.size() && stk.top() < (num[i]) && del < d){
				
				//cout << "pop: " << stk.top() << "\n";
				
				stk.pop();
				del++;
				
			}
			
			stk.push(num[i]);
			
		}
		
		while(del < d){
			
			stk.pop();
			del++;
			
		}
		
		string ans = "";
		
		while(stk.size()){
			
			ans += stk.top();
			stk.pop();
			
		}
		
		for(int i=n-d-1;i>=0;i--)
			cout << ans[i];
		
		cout << "\n";
		
	}
	
	return 0;
}