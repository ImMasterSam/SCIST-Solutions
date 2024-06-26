#include<iostream>
using namespace std;

int main(){
	
	int  s, ans=0;
	cin >> s;
	
	for(int i=0;i<3;i++){
		if(s%10==1)
			ans++;
		s /= 10;
	}
	
	cout << ans;
	
	return 0;
}