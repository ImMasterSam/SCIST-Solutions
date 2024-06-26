#include<iostream>
using namespace std;

string s;

bool solve(int l, int r, int mistake){
	
	for(;l<r;l++, r--){
		
		if(s[l] == s[r])
			continue;
		
		else{
			
			if(mistake)
				return false;
			else
				return solve(l+1, r, mistake+1) || solve(l, r-1, mistake+1);
			
		}
			
		
	}
	
	return true;
	
}

int main(){
	
	int n;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		
		cin >> s;
		
		cout << (solve(0, s.size()-1, 0) ? "YES\n": "NO\n");
		
	}
	
	return 0;
}