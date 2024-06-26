#include<iostream>
using namespace std;

long long get(long long n){
	
	long long t = n;
	
	while(t){
		
		n += t%10;
		t /= 10;
		
	}
	
	return n%100000;
	
}

int main(){
	
	long long n, k;
	long long non_len;
	long long rep_len;
	long long index = 0;
	
	int rank[100005] = {0};
	
	cin >> n >> k;
	
	long long ans = n;
	
	while(1){
		
		rank[n] = index++;
		//cout << n << "\n";
		
		n = get(n);
		
		if(rank[n] != 0){
			
			non_len = rank[n];
			rep_len = index - rank[n];
			
			//cout << non_len << " " << rep_len << "\n";
			break;
			
		}
		
	}
	
	long long times;
	
	times = (k-non_len)%rep_len + non_len;
	
	for(int i=0;i<times;i++){
		
		ans = get(ans);
		
	}
	
	cout << ans << "\n";
	
	return 0;
}