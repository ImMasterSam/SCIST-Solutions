#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main(){
	
	int n;
	cin >> n;
	
	map<int, int> fac[n];
	map<int, int> total;
	map<int, int> require;
	int MAX_SCORE = 1;
	
	for(int i=0, x;i<n;i++){
		
		cin >> x;
		
		for(int j=2;j*j<=x;j++){
			
			while(x % j == 0){
				
				fac[i][j]++;
				total[j]++;
				x /= j;
				
				
			}
			
		}
		
		if(x > 1){
			
			fac[i][x]++;
			total[x]++;
			
		}
		
	}
	
	for(auto &i : total){
		
		//cout << i.f << ": " << i.s << "\n";
		
		while(i.s >= n){
			
			MAX_SCORE *= i.f;
			i.s -= n;
			require[i.f]++;
			
		}
		
	}
	
	int step = 0;
	
	for(int i=0;i<n;i++){
		
		for(auto j : require){
			
			if(j.s > fac[i][j.f])
				step += j.s - fac[i][j.f];
			
		}
		
	}
	
	cout << MAX_SCORE << " " << step << "\n";
	
	return 0;
}