#include <iostream>
using namespace std;

int main(){
	
	int t;
	string s;
	cin >> t >> s;
	
	for(int i=0;i<t;i++){
		
		if(s[i]<='Z')
			cout << (char)(s[i] + (1 << 5));
		else if(s[i]>='a')
			cout << (char)(s[i] - (1 << 5));
		
	}
	cout << "\n";
		
	return 0;
}