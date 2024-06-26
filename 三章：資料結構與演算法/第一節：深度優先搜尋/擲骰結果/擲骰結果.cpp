#include <iostream>
using namespace std;

int a, b, c, k;
int ans = 0;

void dfs(int step, int total){
	
	if(step == a){
		
		if(total + c >= k)
			ans++;
		return;
		
	}
	
	for(int i=1;i<=b;i++){
		
		dfs(step+1, total+i);
		
	}
	
}

int main(){
	
	cin >> a >> b >> c >> k;
	
	dfs(0, 0);
	
	cout << ans;
	
	return 0;
}