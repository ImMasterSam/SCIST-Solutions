#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ //BOOST

	int n, k;
	cin >> n >> k;
	
	set<int> SET;
	map<int, int> freq;
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	int left = 0;
	int MAX = 0;
	// Sliding Window
	for(int i=0;i<n;i++){
		
		SET.insert(arr[i]);
		freq[arr[i]]++;
		
		while(SET.size() > k){
			
			int erase_int = arr[left++];
			
			freq[erase_int]--;
			
			if(freq[erase_int] <= 0){
				
				SET.erase(erase_int);
				
			}
			
		}
		
		MAX = max(MAX, i - left + 1);
		
	}
	
	cout << MAX << "\n";
	
	return 0;
}
