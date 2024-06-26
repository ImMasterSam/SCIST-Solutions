#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		
		int n;
		scanf("%d", &n);
		
		int a[30001] = {0};
		
		for(int i=0;i<n;i++){
			
			int x;
			scanf("%d", &x);
			a[x]++;
			
		}
		
		int l=0, r=30000;
		
		long long ans = 0;
		
		while(n > 1){
			
			while(!a[l]) l++;
			while(!a[r]) r--;
			
			ans += r-l;
			
			a[l]--;a[r]--;
			
			n -= 2;
			
		}
		
		printf("%lld ", ans);
		
		if(n == 0)
			printf("%d\n", l);
		else{
			
			while(!a[l]) l++;
			printf("%d\n", l); 
			
		}
		
	}
	
	return 0;
}