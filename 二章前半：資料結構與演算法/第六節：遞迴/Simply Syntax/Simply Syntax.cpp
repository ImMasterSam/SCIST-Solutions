#include<iostream>
using namespace std;

bool solve(string s){
	
	int valid = 0;
	
	 for(int i=s.size()-1;i>=0;i--){
	 	
	 	if(s[i]>='p' && s[i]<='z')
	 		valid++;
	 	
	 	else if(s[i] == 'N'){
	 		
	 		if(valid == 0)
	 			return false;
	 		
	 	}
	 	
	 	else if(s[i]=='C' || s[i]=='D' || s[i]=='E' || s[i]=='I'){
	 		
	 		if(valid < 2)
	 			return false;
	 		else
	 			valid--;
	 		
	 	}
	 	else
	 		return false;
	 	
	 }
	
	return (valid == 1);
}

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		cout << (solve(s) ? "YES\n" : "NO\n");
		
	}
	
	return 0;
}