#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

vector<string> str;
int used[15] = {0};

void dfs(int step, int u, int size){
	
	if(u == size){
		
		bool first = true;
		for(int i=0;i<str.size();i++){
			if(used[i] == 1){
				if(first)
					first = false;
				else
					cout << ", ";
				cout << str[i];
			}
		}
		
		cout << "\n";
		return;
	}
	
	if(step == str.size())
		return;
	
	if(u<=size-1){
		used[step] = 1;
		dfs(step+1, u+1, size);
		used[step] = 0;
		dfs(step+1, u, size);
	}
	
	
}

int main(){
	
	int t;
	int a, b;
	int p, q;
	string s;
	cin >> t;
	getline(cin, s);
	getline(cin, s);
	
	for(int time=0;time<t;time++){
		
		//cout << time << "\n";
		getline(cin, s);
		int cnt = sscanf(s.c_str(), "%d %d", &a, &b);
		
		getline(cin, s);
		
		while(s != ""){
			
			if(cin.eof()){
				str.push_back(s);
				break;
			}
			
			str.push_back(s);
			getline(cin, s);
			
		}
		
		if(cnt == 0){
			p = 1;
			q = str.size();
		}
		else if(cnt == 1){
			p = a;
			q = a;
		}
		else{
			p = a;
			q = b;
		}
		
		for(int size=p;size<=q;size++){
			
			cout << "Size " << size << "\n";
			dfs(0, 0, size);
			cout << "\n";
			
		}
		
		//cout << p << " " << q << "\n";
		if(time != t-1)
			cout << "\n";
		str.clear();
	}
	
	return 0;
}