#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

int main(){ BOOST

	int n;
	cin >> n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	set<int> SET;
	
	int left = 0;
	int MAX = 0;
	
	for(int i=0;i<n;i++){
		
		while(SET.count(arr[i])){
			
			SET.erase(arr[left++]);
			
		}
		
		SET.insert(arr[i]);
		MAX = max(MAX, i - left + 1);
		
	}
	
	cout << MAX << "\n";
	
	return 0;
}
