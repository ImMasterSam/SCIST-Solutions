#include <bits/stdc++.h>
using namespace std;

// 利用 bits 來存比自己小的字母有誰

string s;
int num = 0;
int alphas = 0;
int les[30];
char path[30];

void dfs(int depth, int used){
	
	if(depth == num){
		
		for(int i=0;i<num;i++)
			cout << path[i];
			
		cout << "\n";
		
		return;
		
	}
	
	for(int i=0, cur;i<26;i++){
		
		cur = (1 << i);
		
		if((alphas & cur) != 0 && (used & cur) == 0 && (les[i] & used) == 0){
			
			path[depth] = 'a' + i;
			
			dfs(depth+1, (used|cur));
			
		}
		
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	bool first = true;;
	
	while(getline(cin, s)){
		
		if(s == "")
			continue;
		
		num = 0;
		alphas = 0;
		memset(les, 0, sizeof les);
		
		stringstream ss;
		char c;
		ss << s;
		
		while(ss >> c){
			
			alphas |= (1 << (c-'a'));
			num++;
			
		}
		
		
		ss.str("");
		ss.clear();
		
		getline(cin, s);
		ss << s;
		
		char a, b;
		
		while(ss >> a >> b){
			
			les[a-'a'] |= (1 << (b-'a')); 
			
		}
		
		if(!first)
			cout << "\n";
		
		dfs(0, 0);
		first = false;
		
	}
	
	
	return 0;
}