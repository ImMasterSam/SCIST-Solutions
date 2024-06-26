#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	int path1, path2;
	
	vector<node *> children;
	vector<node *> parent;
	node() : children(), parent() {}
	
};

void dfs1(node *cur, int depth){
	
	if(cur->path1 > depth){
		
		cur->path1 = depth;
		
		for(node *n : cur->parent)
			dfs1(n, depth+1);
		
	}
	
}
void dfs2(node *cur, int depth){
	
	if(cur->path2 > depth){
		
		cur->path2 = depth;
		
		for(node *n : cur->parent)
			dfs2(n, depth+1);
		
	}
	
}

string p, q;
unordered_map<string, node> MAP;

int main(){ BOOST

	while(cin >> p >> q){
		
		if(p == "no.child") break;
		
		node &child = MAP[p];
		node &parent = MAP[q];
		
		child.parent.push_back(&parent);
		parent.children.push_back(&child);
		
	}
	while(cin >> p >> q){
		
		// Zerojudge 特別測資
		if(p == q){
			
			cout << "no relation\n";
			continue;
			
		}
		
		node &a = MAP[p];
		node &b = MAP[q];
		
		for(auto &person : MAP){
			
			person.second.path1 = person.second.path2 = INT_MAX;
			
		}
		
		dfs1(&a, 0);
		dfs2(&b, 0);
		
		// If b.path1 != INT_MAX
		// Then a is b's parent;
		if(b.path1 != INT_MAX){
			
			for(int i=3;i<=b.path1;i++)
				cout << "great ";
			if(b.path1 >= 2)
				cout << "grand ";
			if(b.path1 == 0)
				cout << p << ": " << q << "\n";
			cout << "child\n";
			continue;
		}
		
		// If a.path2 != INT_MAX 
		// Then a is b's parent;
		if(a.path2 != INT_MAX){
			
			for(int i=3;i<=a.path2;i++)
				cout << "great ";
			if(a.path2 >= 2)
				cout << "grand ";
			cout << "parent\n";
			continue;
		}
			
		// get minimum ancestor
		int MIN = INT_MAX;
		node *ancestor;
		for(auto &person : MAP){
			
			int temp = max(person.second.path1, person.second.path2);
			if(temp < MIN){
				
				MIN = temp;
				ancestor = &person.second;
				
			}
			
		}
		if(MIN == INT_MAX){
			
			cout << "no relation\n";
			continue;
			
		}
		
		int n = ancestor->path1;
		int m = ancestor->path2;
		int k = min(n, m) - 1;
		int j = abs(n-m);
		if(k == 0 && j == 0)
			cout << "sibling\n";
		else{
			
			cout << k << " cousin";
			if(j)
				cout << " removed " << j;
			cout << "\n";
			
		}
 		
	}
	
	return 0;
}
