#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	sort(a, a+n);
	
	int l=0, r=n-1;
	stack<int> stk;
	
	while(l<r){
		
		stk.push(a[l++]);
		stk.push(a[r--]);
		
	}
	
	if(l == r)
		stk.push(a[l]);
		
	while(stk.size()){
		
		cout << stk.top() << " ";
		stk.pop();
		
	}
	
	
	return 0;
}