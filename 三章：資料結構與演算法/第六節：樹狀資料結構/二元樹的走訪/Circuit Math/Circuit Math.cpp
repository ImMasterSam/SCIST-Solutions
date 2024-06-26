#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	bool table[n];
	for(int i=0;i<n;i++){
		
		char c;
		cin >> c;
		table[i] = (c=='T'? true : false);
		
	}
	
	stack<bool> stk;
	char c;
	bool a, b;

	while(cin >> c){
		
		switch(c){
			
			case '*':
				a = stk.top(), stk.pop();
				b = stk.top(), stk.pop();
				stk.push(a && b);
				break;
			
			case '+':
				a = stk.top(), stk.pop();
				b = stk.top(), stk.pop();
				stk.push(a || b);
				break;
			
			case '-':
				a = stk.top(), stk.pop();
				stk.push(!a);
				break;
			
			default:
				stk.push(table[c - 'A']);
				break;
			
		}
		
	}
	
	cout << (stk.top() ? 'T' : 'F');
	
	return 0;
}
