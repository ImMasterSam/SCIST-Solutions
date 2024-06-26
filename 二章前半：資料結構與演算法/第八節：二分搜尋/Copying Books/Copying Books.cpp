#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int m, k;
		cin >> m >> k;
		
		long long books[m];
		
		long long min = 0, max = 0;
		
		for(int i=0;i<m;i++){
			
			cin >> books[i];
			
			if(books[i] > min)
				min = books[i];
	
			max += books[i];
			
		}
		
		while(min < max){
			
			long long count = 1, sum = 0;
			
			long long mid = (min+max)/2;
			
			for(int i=0;i<m;i++){
				
				if(sum + books[i] > mid){
					
					count++;
					sum = 0;
					
				}
				
				sum += books[i];
				
			}
			
			if(count > k)
				min = mid+1;
			else
				max = mid;
			
		}
		
		vector<vector<long long>> v(k, vector<long long> ());
		int i=m-1, j=k-1;
		long long sum = 0;
		
		for(i=m-1;i>=0;i--){
			
			if(j>i || sum + books[i] > max){
				
				j--;
				sum = 0;
				
			}
			
			sum += books[i];
			v[j].push_back(books[i]);
			
		}
		
		for(int i=0;i<k;i++){
			
			if(i)
				cout << " / ";
			
			for(int j=v[i].size()-1;j>=0;j--){
				
				cout << v[i][j];
				
				if(j)
					cout << " ";
				
			}
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}