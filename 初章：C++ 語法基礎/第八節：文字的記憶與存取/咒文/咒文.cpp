#include<iostream>
using namespace std;

int main(){
	
	int l, r;
	string s;
	
	while(getline(cin, s)){
		
		bool set = true;
		
		l = 0;r=s.size()-1;
		
		while(l<r){
			
			while(!isalpha(s[l]))
				l++;
			while(!isalpha(s[r]))
				r--;
			
			if(tolower(s[l])!=tolower(s[r])){
				set = false;
				break;
			}
			l++;r--;
			
		}
		
		if(set)
			cout << "SETUP! " << s << "\n";
		else
			cout << s << "\n";
		
	}
		
	return 0;
}