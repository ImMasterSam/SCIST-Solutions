#include<iostream>
using namespace std;

int main(){
	
	string s[100], l;
	int i=0;
	bool re = false;
	
	while(cin >> l){
		for(int j=0;j<i;j++){
			if(s[j]==l)
				re = true;
		}
		
		if(!re)
			s[i++] = l;
	}
	
	if(re)
		cout << "no";
	else
		cout << "yes";
	
	return 0;
}