#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string s;
	
	while(n != 0){
		cin >> s;
		
		int pre_r = -1, pre_d = -1, m = 1e7;
		
		for(int i=0;i<s.size();i++){
			
			if(s[i] == 'Z'){
				m = 0;
				break;
			}
			
			if(s[i] == 'R'){
				if(pre_d != -1){
					m = min(m, i-pre_d);
				}
				pre_r = i;
			}
			
			else if(s[i] == 'D'){
				if(pre_r != -1){
					m = min(m, i-pre_r);
				}
				pre_d = i;
			}
			
		}
		
		cout << m << "\n";
		
		cin >> n;
	}
	
	return 0;
}