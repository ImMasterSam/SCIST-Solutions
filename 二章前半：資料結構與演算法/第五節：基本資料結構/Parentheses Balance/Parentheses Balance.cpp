#include<iostream>
#include<stack>
#include<map>
using namespace std;

map<char, char> mp = {{']', '['}, {')', '('}};

int main(){
	
	stack<char> mystack;
	
	int n;
	string s;
	
	cin >> n;
	cin.ignore();
	
	for(int i=0;i<n;i++){
		
		while(!mystack.empty())
			mystack.pop();
			
		getline(cin, s);
		
		for(int i=0;i<(int)s.size();i++){
			
			if(mystack.size() && mp[s[i]] == mystack.top())
				mystack.pop();
			
			else
				mystack.push(s[i]);
			
		}
		
		if(mystack.size())
			cout << "No\n";
		else
			cout << "Yes\n";
		
	}
	
	return 0;
}