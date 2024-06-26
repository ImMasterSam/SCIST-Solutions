#include<iostream>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	int d=0, sin=0;
	
	while(getline(cin, s)){
		
		for(int i=0;i<(int)s.size();i++){
			
			if(s[i] == '\"'){
				if(d%2 == 0){
					cout << "``";
					d++;
				}
				else{
					cout << "\'\'";
					d++;
				}
			}
			else
				cout << s[i];
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}