#include<iostream>
using namespace std;

int main(){
	
	bool ishiss = false;
	char s[40];
	cin >> s;
	
	for(int i=0;i<40;i++){
		
		if(s[i]=='s' && s[i+1]=='s')
			ishiss = true;
	}
	
	if(ishiss)
		cout << "hiss";
	else
		cout << "no hiss";
	
	return 0;
}