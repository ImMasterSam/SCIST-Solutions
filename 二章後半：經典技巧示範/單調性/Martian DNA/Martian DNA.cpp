#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
	
	int n, k, R;
	cin >> n >> k >> R;
	
	int a[n] = {0};
	
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	unordered_map<int, int> require;
	unordered_map<int, int> freq;
	unordered_set<int> satisfied;
	
	for(int i=0;i<R;i++){
		
		int b, q;
		cin >> b >> q;
		require[b] = q;
		freq[b] = 0;
		
	}
	
	int smallest = INT_MAX;
	int l=0, r=0;
	
	while(r < n){
		
		if(satisfied.size() < require.size()){
			
			int x = a[r];
			
			if(require.find(x) != require.end()){
				
				freq[x]++;
				
				if(freq[x] >= require[x]){
					
					satisfied.insert(x);
					
				}
				
			}
			
		}
		
		if(satisfied.size() == require.size()){
			
			while(satisfied.size() == require.size()){
				
				int x = a[l];
				
				if(require.find(x) != require.end()){
					
					freq[x]--;
					
					if(freq[x] < require[x])
						satisfied.erase(x);
					
				}
				
				l++;
				
			}
			
			smallest = min(smallest, r-l+2);
			
		}
		
		r++;
	}
	
	if(smallest == INT_MAX)
		cout << "IMPOSSIBLE";
	else
		cout << smallest;
	
	return 0;
}