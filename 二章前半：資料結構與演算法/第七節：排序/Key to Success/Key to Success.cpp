#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<int> cA(128, 0);
vector<int> cB(128, 0);

bool cmp_A(const int &a, const int &b){
	
	return cA[a] > cA[b];
	
}

bool cmp_B(const int &a, const int &b){
	
	return cB[a] > cB[b];
	
}

int main(){
	
	int t;
	cin >> t;
	
	bool first = true;
	
	while(t--){
		
		string a, b;
		cin >> a >> b;
		
		cA.assign(128, 0);
		cB.assign(128, 0);
		
		for(int i=0;i<(int)a.size();i++){
			
			cA[a[i]]++;
			
		}
		
		for(int i=0;i<(int)b.size();i++){
			
			cB[b[i]]++;
			
		}
		
		int idx_a[128], idx_b[128];
		
		for(int i=0;i<128;i++){
			
			idx_a[i] = idx_b[i] = i;
			
		}
		
		sort(idx_a, idx_a+128, cmp_A);
		sort(idx_b, idx_b+128, cmp_B);
		
		map<char, char> m;
		
		for(int i=0;i<128;i++){
			
			if(cA[idx_a[i]] == 0 && cB[idx_b[i]] == 0)
				break;
				
			m[(char)idx_b[i]] = (char)idx_a[i];
			
		}
		
		if(!first)
			cout << "\n";
		
		for(int i=0;i<(int)b.size();i++){
			
			cout << m[b[i]];
			
		}
		
		cout << "\n";
		
		first = false;
		
	}
	
	return 0;
}