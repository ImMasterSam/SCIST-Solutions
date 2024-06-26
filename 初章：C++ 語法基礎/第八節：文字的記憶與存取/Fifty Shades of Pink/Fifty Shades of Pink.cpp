#include<iostream>
using namespace std;

int main(){
	
	int n, ans=0;
	cin >> n;
	string s, t;
	
	for(int i=0;i<n;i++){
		
		cin >> s;
		
		for(int j=0;j<s.size()-3;j++){
			
			t = s.substr(j, 4);
			
			for(int k=0;k<4;k++)
				t[k] = tolower(t[k]);
			
			if(t == "pink"||t == "rose"){
				ans++;
				break;
			}
			
		}
		
	}
	
	if(ans)
		cout << ans;
	else
		cout << "I must watch Star Wars with my daughter";
	
	return 0;
}