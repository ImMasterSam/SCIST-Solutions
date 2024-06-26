#include <bits/stdc++.h>
using namespace std;

map<char, char> trans = {{'2', '5'}, {'5', '2'},
						 {'6', '9'}, {'9', '6'}};

string s;
string temp = "";
int freq[10] = {0};
string path = "";
string ans = "~";

bool found = false;
bool transpos = false;

void dfs(int depth){
	
	if(depth == temp.size()){
		
		if(path > temp && path < ans){
			
			ans = path;
			found = true;
			
		}
		else
			transpos = true;
		
		return;
		
	}
	
	for(int i= (transpos ? '0' : temp[depth]);i<='9' && !found;i++){
		
		if(freq[i-'0']){
			
			path[depth] = i;
			freq[i-'0']--;
			dfs(depth+1);
			freq[i-'0']++;
			
		}
		else{
			
			switch(i){
				
				case '2':
					if(freq[5]){
						
						path[depth] = '2';
						freq[5]--;
						dfs(depth+1);
						freq[5]++;
						
					}
					break;
				case '5':
					if(freq[2]){
						
						path[depth] = '5';
						freq[2]--;
						dfs(depth+1);
						freq[2]++;
						
					}
					break;
					
				case '6':
					if(freq[9]){
						
						path[depth] = '6';
						freq[9]--;
						dfs(depth+1);
						freq[9]++;
						
					}
					break;
				case '9':
					if(freq[6]){
						
						path[depth] = '9';
						freq[6]--;
						dfs(depth+1);
						freq[6]++;
						
					}
					break;
				
				default:
					break;
				
			}
			
		}
		
	}
	
	
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while(getline(cin, s)){
		
		if(s == ".")
			break;
		
		memset(freq, 0, sizeof freq);
		transpos = found = false;
		temp = path = "";
		ans = "~";
		
		for(int i=0;i<s.size();i++){
			
			if(s[i] != '.'){
				
				path += "0";
				temp += s[i];
				freq[s[i] - '0']++;
				
			}
			
		}
		
		dfs(0);
		
		if(ans == "~")
			cout << "The price cannot be raised.\n";
		else{
			
			for(int i=0;i<ans.size();i++){
				
				cout << ans[i];
				
				if(i == ans.size()-2)
					cout << ".";
				
			}
			
			cout << "\n";
			
		}
		
	}
	
		
	return 0;
}