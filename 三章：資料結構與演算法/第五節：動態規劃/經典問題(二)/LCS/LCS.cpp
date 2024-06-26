#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){ BOOST

	string a;
	string b;
	
	cin >> a >> b;
	vector<vector<int>> LCS (a.size()+1, vector<int> (b.size()+1, 0));
	vector<vector<int>> pre (a.size()+1, vector<int> (b.size()+1, -1));
	
	for(int i=1;i<=a.size();i++){
		 
		for(int j=1;j<=b.size();j++){
			
			if(a[i-1] == b[j-1]){
				
				LCS[i][j] = LCS[i-1][j-1] + 1;
				pre[i][j] = 1;
				
			}
				
			else{
				
				if(LCS[i-1][j] >= LCS[i][j-1]){
					
					LCS[i][j] = LCS[i-1][j];
					pre[i][j] = 2;
					
				}
					
				else{
					
					LCS[i][j] = LCS[i][j-1];
					pre[i][j] = 3;
					
				}
				
			}
			
		}
		
	}
	
	int i = a.size(), j = b.size();
	string path = "";
	while(i > 0 && j > 0){
		
		switch(pre[i][j]){
			
			case 1:
				path += a[i-1];
				i--;j--;
				break;
			case 2:
				i--;
				break;
			case 3:
				j--;
				break;
			
		}
		
	}
	
	for(int i=path.size()-1;i>=0;i--)
		cout << path[i];
	
	return 0;
}
