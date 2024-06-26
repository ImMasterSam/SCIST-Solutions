#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	
	vector<string> v;
	string s;
	
	string temp = "";
	
	while(getline(cin, s)){
		
		bool cont = false;
		
		for(int i=0;i<(int)s.size();i++){
			
			if(isalpha(s[i])){
				
				temp += tolower(s[i]);
				
			}
			else if(s[i] == '-'){
				
				if(i == (int)s.size()-1)
					cont = true;
				else
					temp += s[i];
				
			}
			else{
				
				if(temp != ""){
					
					v.push_back(temp);
					temp = "";
					
				}
				
			}
			
		}
		
		if(!cont){
			
			if(temp != "")
				v.push_back(temp);
			
			temp = "";
			
		}
		
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0;i<(int)v.size();i++){
		
		if(i){
			
			if(v[i] != v[i-1])
				cout << v[i] << "\n";
			
		}
		else
			cout << v[i] << "\n";
		
	}
	
	
	return 0;
}