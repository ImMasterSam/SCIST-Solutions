#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int parents[50005] = {0};
int rnk[50005] = {0};

void init(){
	
	memset(parents, -1, sizeof parents);
	memset(rnk, -1, sizeof rnk);
	
}

int getRoot(int cur){
	
	if(parents[cur] == -1){
		
		return cur;
		
	}
	
	return parents[cur] = getRoot(parents[cur]);
	
}

void merge(int a, int b){
	
	a = getRoot(a);
	b = getRoot(b);
	
	if(a != b){
		
		if(rnk[a] < rnk[b])
			swap(a, b);
			
		parents[a] = b;
		
		if(rnk[a] == rnk[b])
			rnk[b]--;
		
	}
	
}

int main(){ BOOST

	int time = 1;
	int n, m;
	
	while(cin >> n >> m, n){
		
		cout << "Case " << time++ << ": ";
		init();
		
		int a, b;
		while(m--){
			
			cin >> a >> b;
			merge(a, b);
			
		}
		
		unordered_set<int> Types;
		for(int i=1;i<=n;i++){
			
			Types.insert(getRoot(i));
			
		}
		
		cout << Types.size() << "\n";
		
	}
	
	return 0;
}
