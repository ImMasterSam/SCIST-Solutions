#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int n, m;
vector<int> children[300000];
int box[300000];
int ans = -1;

int init(int cur){
	
	for(int &i : children[cur]){
		
		box[cur] += init(i);
		
	}
	
	return box[cur];
	
}

void input(int cur, int w){
	
	if(children[cur].size() == 0) return;
	
	int left = children[cur][0];
	int right = children[cur][1];
	
	if(box[left] <= box[right]){
		
		box[left] += w;
		ans = left;
		input(left, w);
		
		
	}
	else{
		
		box[right] += w;
		ans = right;
		input(right, w);
		
	}
	
}

int main(){ BOOST

	cin >> n >> m;
	int goods[m];
	for(int i=n;i<=2*n-1;i++)
		cin >> box[i];
	for(int i=0;i<m;i++)
		cin >> goods[i];
	
	int p, s, t;
	for(int i=0;i<n-1;i++){
		
		cin >> p >> s >> t;
		children[p].push_back(s);
		children[p].push_back(t);
		
	}
	
	init(1);
	
	for(int i=0;i<m;i++){
		
		input(1, goods[i]);
		cout << ans << " ";
		
	}
	
	return 0;
}
