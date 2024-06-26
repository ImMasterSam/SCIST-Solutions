#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int n;
string a, b;
unordered_map<char, int> IDX;

void maketree(int l, int r, int A_idx){
	
	if(l >= r) return;
	
	int pos = IDX[a[A_idx]]; // 中點
	
	int leftLen = pos - l; // 左邊子結點數量
	
	maketree(l, pos,  A_idx + 1); // left
	maketree(pos+1, r, leftLen + A_idx + 1); // right
	
	cout << b[pos];
	
}

int main(){ BOOST

	int t;
	cin >> t;
	
	while(t--){
		
		cin >> n >> a >> b;
			
		for(int i=0;i<n;i++)
			IDX[b[i]] = i;
		
		maketree(0, n, 0);
		
		cout << "\n";
		
	}

		
	
	return 0;
}
