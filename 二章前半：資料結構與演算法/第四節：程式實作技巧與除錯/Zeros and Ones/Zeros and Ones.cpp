#include<iostream>
#include<cmath>
using namespace std;

int flag[1000001] = {0};

int main(){
	
	string s;
	int t = 1;
	
	while(cin >> s){
		
		if(s == "")
			break;
		
		int l = s.size();
		
		for(int i=1;i<=l;i++){
			
			flag[i] = flag[i-1] + (s[i-1] == '1');
			
		}
		
		int n;
		cin >> n;
		
		cout << "Case " << t++ << ":\n";
		
		for(int i=0;i<n;i++){
			
			int a, b;
			cin >> a >> b;
			
			int l = min(a, b)+1;
			int r = max(a, b)+1;
			
			//cout << "Count: " << flag[r] - flag[l-1] << "\n";
			
			if(flag[r] - flag[l-1] == 0 || flag[r] - flag[l-1] == r-l+1)
				cout << "Yes\n";
			else
				cout << "No\n";
			
		}
		
	}
	
	return 0;
}