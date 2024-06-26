#include<iostream>
using namespace std;

int main(){
	
	int n, g;
	string s, t;
	cin >> n;
	
	while(n!=0){
		
		cin >> s;
		g = (int)s.size()/n;
		
		for(int i=0;i<s.size();i+=g){
			
			t = s.substr(i, g);
			
			for(int j=g-1;j>=0;j--)
				cout << t[j];
			
		}
		
		cout << "\n";
		cin >> n;
		
	}
		
	return 0;
}