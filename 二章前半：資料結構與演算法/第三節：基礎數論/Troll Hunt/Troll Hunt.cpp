#include<iostream>
using namespace std;

int main(){
	
	int b, k, g;
	
	cin >> b >> k >> g;
	
	b--; // the one with the troll
	
	int ans = b/(k/g);
	
	if(b%(k/g))
		ans++;
		
	cout << ans;
	
	
	return 0;
}