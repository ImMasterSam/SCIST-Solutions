#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
char str[20][20] = {0};

bool cmp(const int &a, const int &b){
	
	for(int i=0;i<r;i++){
		
		char ca = tolower(str[i][a]);
		char cb = tolower(str[i][b]);
		
		if(ca != cb)
			
			return ca < cb;
		
	}
	
	return a < b;
	
}

int main(){
	
	while(cin >> r >> c, (r||c)){
		
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++)
				cin >> str[i][j];
			
		}
		
		int idx[c];
		
		for(int i=0;i<c;i++)
			idx[i] = i;
			
		sort(idx, idx+c, cmp);
		
		for(int i=0;i<r;i++){
			
			for(int j=0;j<c;j++){
				
				cout << str[i][idx[j]];
				
			}
			
			cout << "\n";
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}