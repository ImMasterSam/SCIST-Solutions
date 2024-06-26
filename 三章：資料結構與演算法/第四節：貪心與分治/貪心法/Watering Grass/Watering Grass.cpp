#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool cmp(const pair<double, double> &a, const pair<double, double> &b){
	
	if(a.f == b.f)
		return a.s < b.s;
	else
		return a.f < b.f;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l, w;
	
	while(cin >> n >> l >> w){
		
		int ans = 0;
		pair<double, double> arr[n]; // first: left, second: right
		
		for(int i=0, pos, rad;i<n;i++){
			
			cin >> pos >> rad;
			
			if(rad < (w/2.0)){
				
				arr[i].f = l + 5000;
				arr[i].s = l + 5000;
				continue;
				
			}
			else{
				
				double len = sqrt(pow(rad, 2) - pow(w/2.0, 2));
				
				arr[i].f = pos - len;
				arr[i].s = pos + len;
				
			}
			
			if(arr[i].f <= 0 && arr[i].s >= l) ans = 1;
			
		}
		
		if(ans)
			cout << "1\n";
		else{
			
			ans = 1;
			sort(arr, arr+n, cmp);
			
			for(int i=0;i<n;i++){
				
				if(arr[i].f > l)
					break;
					
				int right_pos = -1;
				
				for(int j=i+1;j<n;j++){
					
					if(right_pos == -1 && arr[i].s >= arr[j].f)
						right_pos = j;
					else if(arr[i].s >= arr[j].f && arr[j].s > arr[right_pos].s)
						right_pos = j;
					
				}
				
				i = right_pos - 1;
				ans++;
				
				if(right_pos != -1 && arr[right_pos].s >= l)
					break;
				
				if(right_pos == -1){
					
					ans = 0;
					break;
					
				}
				
			}
			
			if(ans && arr[0].f <= 0)
				cout << ans << "\n";
			else
				cout << "-1\n";
			
		}
		
	}
	
	
	return 0;
}