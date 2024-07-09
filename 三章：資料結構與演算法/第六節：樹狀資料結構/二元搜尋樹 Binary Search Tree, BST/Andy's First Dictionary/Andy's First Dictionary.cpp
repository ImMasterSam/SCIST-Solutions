#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	string data;
	int left, right;
	
};

node pool[10000];
int root, pp = 1;

void insert(string t, int &pos){
	
	if(!pos){
		
		pos = pp++;
		pool[pos].data = t;
		pool[pos].left = pool[pos].right = 0;
		return;
		
	}
	
	if(t < pool[pos].data){
		
		insert(t, pool[pos].left);
		
	}
	else{
		
		insert(t, pool[pos].right);
		
	}
	
}

int find_max(int &pos){
	
	if(pool[pos].right){
		
		return find_max(pool[pos].right);
		
	}
	
	return pos;
	
}

void erase(string t, int &pos){
	
	if(!pos)
		return;
	
	if(t == pool[pos].data){
		
		if(!pool[pos].left){
			
			pos = pool[pos].right;
			
		}
		else if(!pool[pos].right){
			
			pos = pool[pos].left;
			
		}
		else{
			
			int nxt = find_max(pool[pos].left);
			pool[pos].data = pool[nxt].data;
			pool[nxt] = pool[pool[nxt].left];
			
		}
		
	}
	
	if(t < pool[pos].data){
		
		erase(t, pool[pos].left);
		
	}
	else{
		
		erase(t, pool[pos].right);
		
	}
	
}


int main(){ BOOST
	
	unordered_set<string> S;
	
	string buffer;
	int count = 0;
	while(getline(cin, buffer)){
		
		string temp = "";
		for(char c : buffer){
			
			if(isalpha(c))
				temp += tolower(c);
			else{
				
				if(temp != ""){
					
					if(!S.count(temp)){
						
						root = 1;
						insert(temp, root);
						S.insert(temp);
						count++;
						
					}
					
					temp = "";
					
				}
				
			}
			
		}
		
		if(temp != ""){
			
			if(!S.count(temp)){
				
				root = 1;
				insert(temp, root);
				S.insert(temp);
				count++;
				
			}
			
			temp = "";
			
		}	
		
	}
	
	stack<string> stk;
	
	for(int i=0;i<count-1;i++){
		
		root = 1;
		int idx = find_max(root);
		stk.push(pool[idx].data);
		root = 1;
		erase(pool[idx].data, root);
		
	}
	
	int idx = find_max(root);
	stk.push(pool[idx].data);
	
	while(!stk.empty()){
		
		cout << stk.top() << "\n";
		stk.pop();
		
	}
	
	return 0;
}
