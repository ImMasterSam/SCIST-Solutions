#include<iostream>
#include<cctype>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	cin.ignore();
	
	string s;
	
	for(int i=0;i<n;i++){
		
		getline(cin, s);
		
		int tbl[26] = {0};
		int max = 0;
		
		for(int j=0;j<(int)s.size();j++){
			
			if(isalpha(s[j])){
				
				char c = tolower(s[j]);
				
				tbl[c-'a']++;
				
				if(tbl[c-'a'] > max)
					max = tbl[c-'a'];
				
			}
			
		}
		
		for(int j=0;j<26;j++){
			
			if(tbl[j] == max)
				cout << (char)(j+'a');
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}