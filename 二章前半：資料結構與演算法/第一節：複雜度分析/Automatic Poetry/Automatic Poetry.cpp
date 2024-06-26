#include<iostream>
using namespace std;

int main(){
	
	string s;
	int n;
	cin >> n;
	cin.ignore();
	
	for(int i=0;i<n;i++){
		
		string sub[5];
		int index = 0;
		getline(cin, s);
		
		for(int j=0;j<5;j++)
			sub[j] = "";
		
		for(;index<s.size();index++){
			if(s[index] == '<'){
				index++;
				break;
			}
			sub[0] += s[index];
		}
		for(;index<s.size();index++){
			if(s[index] == '>'){
				index++;
				break;
			}
			sub[1] += s[index];
		}
		for(;index<s.size();index++){
			if(s[index] == '<'){
				index++;
				break;
			}
			sub[2] += s[index];
		}
		for(;index<s.size();index++){
			if(s[index] == '>'){
				index++;
				break;
			}
			sub[3] += s[index];
		}
		for(;index<s.size();index++){
			sub[4] += s[index];
		}
		
		for(int i=0;i<s.size();i++){
			if(s[i] == '<' || s[i] == '>')
				continue;
			cout << s[i];
		}
		
		cout << "\n";
		
		getline(cin, s);
		
		for(int index=0;index<s.size();index++){
			if(s[index]=='.' && s[index+1]=='.' && s[index+2]=='.')
				break;
			cout << s[index];
		}
		
		cout << sub[3] << sub[2] << sub[1] << sub[4] << "\n";
		
	}
	
	
	return 0;
}