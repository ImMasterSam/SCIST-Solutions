#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

const int NOT_EXIST = -1;

struct node{
	
	int data;
	vector<int> children;
	int parent;
	
};

node tree[200000];

void travel(int idx, int depth){
	
	cout << "========\n";
	cout << "Node " << idx << " (depth: " << depth << "):\n";
	cout << "Parent: " << tree[idx].parent << "\n";
	cout << "Children(" << tree[idx].children.size() << "):\n   ";
	
	for(int &i : tree[idx].children)
		cout << i << " ";
		
	cout << "\n";
	
	for(int &i : tree[idx].children)
		travel(i, depth+1);
	
}

int main(){ BOOST

	int n;
	
	while(cin >> n){
		
		for(int i=0;i<n;i++){
			
			cin >> tree[i].data;
			tree[i].children.clear();
			tree[i].parent = NOT_EXIST;
			
		}
		
		for(int i=0;i<n-1;i++){
			
			int a, b;
			cin >> a >> b;
			tree[b].parent = a;
			tree[a].children.push_back(b);
			
		}
		
		for(int i=0;i<n;i++){
			
			if(tree[i].parent == NOT_EXIST){ // Root
				
				travel(i, 0);
				break;
				
			}
			
		}
		
	}
	
	return 0;
}
