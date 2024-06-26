#include <iostream>
#include <vector>
using namespace std;

bool in(const string &s, const vector<string>v){
	
	for(int i=0;i<v.size();i++){
		
		if(s == v[i])
			return true;
		
	}
	
	return false;
	
}

string toupper(string &s){
	
	string temp = "";
	
	for(int i=0;i<s.size();i++){
		
		temp += toupper(s[i]);
		
	}
	
	return temp;
	
}

int main(){
	
	vector<string> ignore;
	ignore.reserve(55);
	string s;
	
	while(cin >> s){
		
		if(s == "::")
			break;
		
		ignore.push_back(s);
		
	}
	
	cin.ignore();
	
	vector<vector<string>> sens(205);
	int n = 0;
	string buffer;
	
	while(getline(cin, buffer)){
		
		//cout << buffer << "\n";
		
		string temp = "";
		
		for(int i=0;i<buffer.size();i++){
			
			if(buffer[i] == ' ' && temp != ""){
				
				if(temp != ""){
					
					sens[n].push_back(temp);
					temp = "";
					
				}
				
			}
			
			else
				temp += buffer[i];
			
		}
		
		if(temp != ""){
			
			sens[n].push_back(temp);
			temp = "";
			
		}
		
		n++;
		
	}
	
	vector<pair<string, string>> HEAP;
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<sens[i].size();j++){
			
			if(in(sens[i][j], ignore))
				continue;
				
			string temp = "";
				
			for(int k=0;k<sens[i].size();k++){
				
			}
			
		}
		
	}
	
	/*
	for(int i=0;i<n;i++){
		
		for(auto j : sens[i]){
			
			cout << j << ", ";
			
		}
		
		cout << "\n";
		
	}*/
	
	return 0;
}