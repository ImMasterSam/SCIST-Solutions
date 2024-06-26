#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long s, c, k;
	cin >> s >> c >> k;
	
	long long arr[100000] = {0};
	
	for(int i=0;i<s;i++)
		cin >> arr[i];
		
	sort(arr, arr+s);
	
	int washer = 1;
	long long last_c = arr[0];
	int n = 0;
	
	for(int i=0;i<s;i++){
		
		if(arr[i] - last_c > k || n >= c){
			
			//cout << "idx: " << i << "\n";
			
			last_c = arr[i];
			washer++;
			n = 1;
			
		}
		else
			n++;
		
	}
	
	cout << washer;
	
	return 0;
}