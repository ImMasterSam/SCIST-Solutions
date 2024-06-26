#include<iostream>
using namespace std;

string s;

int solve(string end){
	
	int ans = 1;
	int temp = 0;
	
	while(cin >> s){
		
		if(s == end)
			break;
		
		if(s == "S")
			continue;
			
		if(s == "IF"){
			
			temp = solve("ELSE");
			temp += solve("END_IF");
			
			ans *= temp;
			
		}
		
		
	}
	
	return ans;
	
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		cout << solve("ENDPROGRAM") << "\n";
		
	}
	
	
	return 0;
}