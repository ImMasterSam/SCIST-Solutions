#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

vector<vector<int>> box(30, vector<int>(10));
vector<int> idx(30);

int k, n;

bool cmp(const int &a, const int &b){
	
	for(int i=0;i<n;i++){
		
		if(box[a][i] != box[b][i])
			return box[a][i] < box[b][i];
		
	}
	
	return false;
	
}

bool larger(int a, int b){
	
	for(int i=0;i<n;i++){
		
		if(box[idx[a]][i] <= box[idx[b]][i])
			return false;
		
	}
	
	return true;
	
}

void output(vector<int> &pre, int i){
	
	if(pre[i] != -1)
		output(pre, pre[i]);
	
	cout << idx[i]+1 << " ";
	
}

int main(){ BOOST

	while(cin >> k >> n){
		
		for(int i=0;i<k;i++){
			
			idx[i] = i;
			
			for(int j=0;j<n;j++){
				
				cin >> box[i][j];
				
			}
			
			sort(box[i].begin(), box[i].begin()+n);
			
		}
		
		sort(idx.begin(), idx.begin()+k, cmp);
		
		vector<int> LIS(k, 0);
		vector<int> pre(k, -1);
		int maxIDX = 0;
		
		for(int i=0;i<k;i++){
			
			for(int j=i+1;j<k;j++){
				
				if(larger(j, i)){
					
					if(LIS[i] + 1 > LIS[j]){
						
						LIS[j] = LIS[i] + 1;
						
						if(LIS[j] > LIS[maxIDX])
							maxIDX = j;
						
						pre[j] = i;
						
					}
					
				}
				
			}
			
		}
		/*
		for(int i=0;i<k;i++){
			
			cout << idx[i]+1 << "->";
			
			for(int j=0;j<n;j++){
				
				cout << box[idx[i]][j] << " ";
				
			}
			
			cout << "\n";
			
		}
		*/
		cout << LIS[maxIDX] + 1 << "\n";
		output(pre, maxIDX);
		cout << "\n";
		
		
		
	}
	
	return 0;
}
