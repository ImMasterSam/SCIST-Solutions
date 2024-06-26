#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<int> primes;

bool isprime(int n){
	
	if(n>2 && n%2 == 0)
		return false;
	
	if(n>3 && n%3 == 0)
		return false;
		
	for(int i=6;i<=sqrt(n)+1;i += 6){
		
		if(n % (i-1) == 0)
			return false;
		
		if(n % (i+1) == 0)
			return false;
		
	}
	
	return true;
}

bool used[1005] = {0};
queue<pair<int, int>> q;

void clear(queue<pair<int, int>> &q){
	
	queue<pair<int, int>> empty;
	swap(q, empty);
	
}

int bfs(int s, int t){
	
	pair<int, int> cur, nxt;
	
	cur.f = s;
	cur.s = 0;
	
	q.push(cur);
	used[s] = true;
	
	while(q.size()){
		
		cur = q.front(), q.pop();
		
		if(cur.f == t){
			
			return cur.s;
			
		}
		
		for(int i=0;i<primes.size() && primes[i]<cur.f;i++){
			
			if(cur.f%primes[i] == 0 && cur.f+primes[i]<=t){
				
				nxt = cur;
				nxt.f += primes[i];
				nxt.s++;
				
				if(!used[nxt.f]){
					
					used[nxt.f] = true;
					q.push(nxt);
					
				}
				
			}
			
		}
		
	}
	
	return -1;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=2;i<=1005;i++){
		
		if(isprime(i))
			primes.push_back(i);
		
	}
	
	int s, t;
	int time = 1;
	
	while(cin >> s >> t){
		
		if(s==0 && t==0)
			break;
			
		memset(used, false, sizeof(used));
		clear(q);
		
		cout << "Case " << time++ << ": ";
		cout << bfs(s, t) << "\n";
		
	}
	
	return 0;
}