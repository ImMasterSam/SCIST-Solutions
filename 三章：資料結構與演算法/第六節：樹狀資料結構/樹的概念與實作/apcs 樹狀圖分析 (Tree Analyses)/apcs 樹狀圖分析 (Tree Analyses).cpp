#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

struct node{
	
	long long height = 0;
	vector<int> children, parents;
	
};

node tree[100005];

void dfs(int cur, long long height){
	
	if(height >= tree[cur].height){
		
		tree[cur].height = height;
		
		for(int par : tree[cur].parents){
			
			dfs(par, height+1);
			
		}
		
	}
	
}

int main(){ BOOST

	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		
		int k;
		cin >> k;
		for(int kid=0;kid<k;kid++){
			
			int child;
			cin >> child;
			tree[i].children.push_back(child);
			tree[child].parents.push_back(i);
			
		}
		
	}
	
	for(int i=1;i<=n;i++){
		
		if(tree[i].children.size() == 0){
			
			dfs(i, 0);
			
		}
		
	}
	
	long long ans = 0;
	
	for(int i=1;i<=n;i++){
		
		ans += tree[i].height;
		
		if(tree[i].parents.size() == 0)
			cout << i << "\n"; // Root
		
	}
	
	cout << ans;
	
	return 0;
}
