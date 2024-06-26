#include<iostream>
using namespace std;

int main(){
	
	string mes, key, ans;
	
	cin >> mes >> key;
	
	int t;
	
	ans.resize(mes.size(), ' ');
	
	for(int i=0;i<mes.size();i++){
		
		if(i>=key.size()){
			
			t = mes[i]-ans[i-key.size()]+'A';
			
			while(t<'A'){
				t += 26;
			}
			ans[i] = (char)(t);
		}
		
		else{
			
			t = mes[i]-key[i]+'A';
			
			while(t<'A')
				t += 26;
			ans[i] = (char)(t);
		}
		
	}
	
	cout << ans;
		
	return 0;
}