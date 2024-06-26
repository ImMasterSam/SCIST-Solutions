#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s[205];

bool cmp(const int &a, const int &b){
	
	if(s[a][0] != s[b][0])
		return s[a][0] < s[b][0];
		
	if(s[a][1] != s[b][1])
		return s[a][1] < s[b][1];
		
	return a < b;
	
}

int main(){
	
	while(cin >> n, n){
		
		int idx[n] = {0};
		
		for(int i=0;i<n;i++){
			
			idx[i] = i;
			cin >> s[i];
			
		}
		
		sort(idx, idx+n, cmp);
		
		for(int i=0;i<n;i++){
			
			cout << s[idx[i]] << "\n";
			
		}
		
		cout << "\n";
		
	}
	
	
	return 0;
}