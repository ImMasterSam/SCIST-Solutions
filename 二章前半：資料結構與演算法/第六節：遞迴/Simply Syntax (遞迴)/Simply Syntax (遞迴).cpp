#include<iostream>
using namespace std;

int solve(string s){
	
	if(s.size() == 1){
		
		if(s[0]>='p' && s[0]<='z')
			return 1;
		else
			return 0;
		
	}
	
	else if(s[0] == 'N'){
		
		return solve(s.substr(1, s.size()-1));
		
	}
	
	else if(s[0]=='C' || s[0]=='D' || s[0]=='E' || s[0]=='I'){
		
		int flag = false;
		
		if(s.size()<3)
			return 0;
		
		for(int i=1;i<s.size()-1;i++){
			
			int a = solve(s.substr(1, i));
			if(a == 0)
				continue;
			int b = solve(s.substr(1+i, s.size()-1-i));
			
			if(a && b){
				
				flag = true;
				break;
				
			}
			
		}
		
		if(flag)
			return 1;
		else
			return 0;
		
	}
	
	return 0;
}

int main(){
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(0);*/
	
	string s;
	
	int t = 1;
	
	while(cin >> s){
		
		int res = solve(s);
		
		//cout << s << "\n";
		
		cout << t++ << ": ";
		
		if(res)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	
	return 0;
}