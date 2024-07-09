#include <bits/stdc++.h>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0); 
using namespace std;

long long ID[200005] = {0};
int idx[200005] = {0};

bool cmp(const int &a, const int &b){
	
	return ID[a] < ID[b];
	
}

int main(){ BOOST

	long long n, k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> ID[i];
	
	
	long long arr[n] = {0};
	for(int i=0;i<n;i++){
		
		idx[i] = i;
		arr[i] = k / n;
		
	}
		
	sort(idx, idx+n, cmp);
	
	for(int i=0;i<k%n;i++)
		arr[idx[i]]++;
		
	for(int i=0;i<n;i++)
		cout << arr[i] << "\n";
	
	
	return 0;
}
