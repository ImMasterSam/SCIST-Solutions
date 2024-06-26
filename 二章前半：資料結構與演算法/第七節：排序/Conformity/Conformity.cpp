#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
	
	for(int i=0;i<5;i++){
		
		if(a[i] != b[i])
			return a[i] < b[i];
		
	}
	
	return false;
	
}

bool list_cmp(const vector<int> &a, const vector<int> &b){
	
	for(int i=0;i<5;i++){
		
		if(a[i] != b[i])
			return false;
		
	}
	
	return true;
	
}

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		vector<vector<int>> a(n, vector<int> (5, 0));
		
		for(int i=0;i<n;i++){
			
			for(int j=0;j<5;j++)
				cin >> a[i][j];
				
			sort(a[i].begin(), a[i].end());
			
		}
		
		sort(a.begin(), a.end(), cmp);
		
		int count[n] = {0};
		int tn = 0;
		
		int max = 0;
		int i, j;
		
		for(i=0;i<n;i=j){
			
			for(j=i+1;j<n && list_cmp(a[j], a[i]); j++);
			
			count[tn] = j - i;
			
			if(count[tn] > max)
				max = count[tn];
			
			tn++;
			
		}
		
		int ans = 0;
		
		for(i=0;i<tn;i++){
			
			if(count[i] == max)
				ans += count[i];
			
		}
		
		cout << ans << "\n";
		
		/*
		for(int i=0;i<n;i++){
			
			for(int j=0;j<5;j++)
				cout << a[i][j] << " ";
				
			cout << "\n";
			
		}*/
		
	}
	
	return 0;
}