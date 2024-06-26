#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

string a, b;
stringstream ss;
int x;
vector<int> A, B;
unordered_map<int, int> IDX;
vector<int> children[10005];

int MIN = INT_MAX;
int ans = -1;

int maketree(int l, int r, int B_idx){
	
	if(l >= r) return -1;
	
	int pos = IDX[B[B_idx]];
	int rightLen = r - pos - 1;
	
	int right = maketree(pos+1, r, B_idx+1);
	if(right != -1)
		children[A[pos]].push_back(right);
		
	int left = maketree(l, pos, B_idx + rightLen + 1);
	if(left != -1)
		children[A[pos]].push_back(left);
	
	return A[pos];
	
}

void DFS(int cur, int total){
	
	if(children[cur].size() == 0){
		
		if(total+cur < MIN){
			
			MIN = total+cur;
			ans = cur;
			
		}
		if(total+cur == MIN)
			ans = min(ans, cur);
		
	}
	else{
		
		for(int &child : children[cur])
			DFS(child, total+cur);
		
	}
	
}

int main(){ BOOST

	while(getline(cin, a), getline(cin, b)){
		
		for(int i=0;i<10005;i++)
			children[i].clear();
			
		A.clear(), B.clear();
		MIN = INT_MAX;
		ans = -1;
		
		ss.str(""), ss.clear();
		ss << a;
		while(ss >> x){
			
			A.push_back(x);
			
		}
		ss.str(""), ss.clear();
		B.assign(A.size(), 0);
		ss << b;
		for(int i=A.size()-1;i>=0;i--){
			
			ss >> x;
			B[i] = x;
			
		}
		
		for(int i=0;i<B.size();i++)
			IDX[A[i]] = i;
			
		maketree(0, A.size(), 0);
		DFS(B[0], 0);
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
