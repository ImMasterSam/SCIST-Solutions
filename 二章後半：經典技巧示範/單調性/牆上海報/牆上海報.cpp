#include <iostream>
using namespace std;

int h[200005] = {0};
int w[5005] = {0};

int n, k;

bool check(int x){
	
	int width = 0;
	int idx = 0;
	
	for(int i=0;i<n;i++){
		
		if(h[i] >= x)
			width++;
		else
			width = 0;
			
		if(width>=w[idx]){
			
			width -= w[idx++];
			
		}
		
		if(idx == k)
			break;
		
	}
	
	return idx == k;
	
}

int BinarySearch(){
	
	int l = 0, r = 1e9;
	
	int ans = 0;
	
	while(l<=r){
		
		int mid = (l+r)/2;
		
		if(check(mid)){
			
			ans = mid;
			l = mid + 1;
			
		}
		else
			r = mid - 1;
		
	}
	
	return ans;
	
}

int main(){
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> h[i];
	for(int i=0;i<k;i++)
		cin >> w[i];
		
	cout << BinarySearch();
	
		
	return 0;
}