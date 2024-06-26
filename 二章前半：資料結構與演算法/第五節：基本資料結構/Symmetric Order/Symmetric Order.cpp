#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	stack<string> s;
	
	int n, t=1;
	string str;
	
	while(cin >> n, n){
		
		cin.ignore();
		
		cout << "SET " << t++ << "\n";
		
		for(int i=0;i<n;i++){
			
			getline(cin, str);
			
			s.push(str);
			
			if(i%2 == 0){
				
				cout << s.top() << "\n";
				s.pop();
				
			}
			
		}
		
		while(!s.empty()){
				
			cout << s.top() << "\n";
			s.pop();
			
		}
		
	}
	
	return 0;
}