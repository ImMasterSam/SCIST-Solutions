#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define f first
#define s second

vector<string> str;
bool side[205][205] = {0};
bool used[205] = {0};
queue<pair<int, int>> q;

bool check(const string &a, const string &b){
	
	if(a.size() != b.size())
		return false;
	
	int dif = 0;
	
	for(int i=0;i<a.size();i++){
		
		if(a[i] != b[i])
			dif++;
		
	}
	
	return dif == 1;
	
}

void clear(queue<pair<int, int>> &q){
	
	queue<pair<int, int>> empty;
	swap(q, empty);
	
}

int bfs(int s, int e){
	
	pair<int, int> cur, nxt;
	
	cur.f = s;
	cur.s = 0;
	
	q.push(cur);
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.f == e){
			
			return cur.s;
			
		}
		
		for(int i=0;i<str.size();i++){
			
			if(!used[i] && side[cur.f][i]){
				
				nxt = cur;
				nxt.f = i;
				nxt.s++;
				
				used[i] = true;
				q.push(nxt);
				
			}
			
		}
		
	}
	
	
	return -1;
}

int main(){
	
	int t;
	cin >> t;
	
	bool first = true;
	
	while(t--){
		
		memset(side, false, sizeof(side));
		str.clear();
		
		string s;
		while(cin >> s){
			
			if(s == "*")
				break;
			
			str.push_back(s);
			
			for(int i=0;i<str.size()-1;i++){
				
				if(check(str[i], s))
					side[i][str.size()-1] = side[str.size()-1][i] = true;
				
			}
			
		}
		
		cin.ignore();
		
		if(!first)
			cout << "\n";
		
		while(getline(cin, s)){
			
			if(s == "")
				break;
			
			char a[15], b[15];
				
			sscanf(s.c_str(), "%s %s", a, b);
			
			int start, end;
			
			for(int i=0;i<str.size();i++){
				
				if(str[i] == a)
					start = i;
				
				if(str[i] == b)
					end = i;
				
			}
			
			memset(used, false, sizeof(used));
			clear(q);
			
			cout << a << " " << b << " " << bfs(start, end) << "\n";
			
		}
		
		first = false;
		
	}
	
	return 0;
}