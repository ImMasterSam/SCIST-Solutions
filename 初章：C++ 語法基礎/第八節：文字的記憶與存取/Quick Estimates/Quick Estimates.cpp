#include<iostream>
using namespace std;

int main(){
	
	string s;
	int n;
	cin >> n;
	getline(cin, s);
	
	for(int i=0;i<n;i++){
		
		getline(cin, s);
		cout << s.size() << "\n";
	}
		
	return 0;
}