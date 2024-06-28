#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int parents[30005] = {0};
int rnk[30005] = {0};

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

	int t;
	cin >> t;
	
	while(t--){
		
		init();
		
		int n, m;
		cin >> n >> m;
		while(m--){
			
			int a, b;
			cin >> a >> b;
			merge(a, b);
			
		}
		
		unordered_map<int, int> freq;
		int MAX = 0;
		
		for(int i=1;i<=n;i++){
			
			int root = getRoot(i);
			freq[root]++;
			
			MAX = max(MAX, freq[root]);
			
		}
		
		cout << MAX << "\n";
		
	}
	
	return 0;
}
