#include<iostream>
#include<stack>
#include<map>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n){
		
		pair<int, int> M[30];
		map<char, int> map;
		
		for(int i=0;i<n;i++){
			
			char c;
			cin >> c;
			map[c] = i;
			cin >> M[i].first >> M[i].second;
			
		}
		
		cin.ignore();
		
		string s;
		
		while(getline(cin, s)){
			
			int sum = 0;
			bool error = false;
			
			pair<int, int> a, b;
			stack< pair<int, int> > stk;
			
			for(int i=0;i<(int)s.size();i++){
				
				if(s[i] == '(')
					continue;
				
				if(s[i] == ')'){
					
					if(stk.size()>=2){
						
						a = stk.top();
						stk.pop();
						b = stk.top();
						stk.pop();
						
						if(b.second == a.first){
							
							sum += b.first * b.second * a.second;
							stk.push(make_pair(b.first, a.second));
							
						}
						else{
							
							error = true;
							break;
							
						}
						
						
					}
					
				}
				else
					stk.push(make_pair(M[map[s[i]]].first, M[map[s[i]]].second));
				
			}
			
			if(stk.size() == 1 && !error)
				cout << sum << "\n";
			else
				cout << "error" << "\n";
			
		}
		
	}
	
	
	return 0;
}