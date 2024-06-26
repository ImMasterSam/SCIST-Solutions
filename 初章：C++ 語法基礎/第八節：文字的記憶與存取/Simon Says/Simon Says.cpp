#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string s;
	getline(cin, s);
	
	for(int i=0;i<n;i++){
		
		getline(cin, s);
		
		if(s.substr(0, 10) == "Simon says")
			cout << s.substr(11) << "\n";
		
	}
		
	return 0;
}