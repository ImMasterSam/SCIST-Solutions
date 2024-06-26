#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &a, const int &b){
	
	return a > b;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, d, r;
	
	while(cin >> n >> d >> r){
		
		if(n == 0 && d == 0 && r == 0)
			break;
		
		int day[100] = {0};
		int night[100] = {0};
		
		for(int i=0;i<n;i++)
			cin >> day[i];
		
		for(int i=0;i<n;i++)
			cin >> night[i];
			
		sort(day, day+n);
		sort(night, night+n, cmp);
		
		int pay = 0;
		
		for(int i=0;i<n;i++){
			
			int total = day[i] + night[i];
			
			if(total > d){
				
				pay += (total - d) * r;
				
			}
			
		}
		
		cout << pay << "\n";
		
	}
	
	return 0;
}