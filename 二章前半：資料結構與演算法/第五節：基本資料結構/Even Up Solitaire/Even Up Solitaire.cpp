#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	stack<int> mystack;
	int n;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		int x;
		cin >> x;
		
		if(mystack.size()){
			
			if(x%2 == mystack.top()%2)
				mystack.pop();
			else
				mystack.push(x);
			
		}
		else
			mystack.push(x);
		
	}
	
	cout << mystack.size();
	
	return 0;
}