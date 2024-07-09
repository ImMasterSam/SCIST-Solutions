#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

using pp = pair<long long, int>;
#define f first
#define s second

int main(){ BOOST

	priority_queue<pp, vector<pp>, greater<pp>> pq;
	
	int n;
	cin >> n;
	
	long long S[n+1];
	for(int i=1;i<=n;i++)
		cin >> S[i];
	for(int i=1;i<=n;i++){
		
		int t;
		cin >> t;
		pq.push(make_pair(t, i));
		
	}
		
	int num_get = 0;
	int ans[n+1] = {0};
	
	while(num_get < n){
		
		pp top = pq.top();
		pq.pop();
		
		if(!ans[top.s]){
			
			ans[top.s] = top.f;
			num_get++;
			
			if(top.s < n)
				pq.push(make_pair(top.f + S[top.s], top.s+1));
			else
				pq.push(make_pair(top.f + S[top.s], 1));
			
		}
		
	}
	
	for(int i=1;i<=n;i++)
		cout << ans[i] << "\n";
	
	return 0;
}
