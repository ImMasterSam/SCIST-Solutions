#include<iostream>
#include<string>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s, t;
	
	while(getline(cin, s)){
		
		bool isp = false;
		
		for(int i=0;i<(int)s.size();i++){
			
			t = s.substr(i, 7);
			
			for(int j=0;j<7;j++)
				t[j] = tolower(t[j]);
			
			if(t == "problem"){
				isp = true;
				break;
			}
			
			
		}
		
		if(isp)
			cout << "yes\n";
		else
			cout << "no\n";
		
		
	}
	
	return 0;
}