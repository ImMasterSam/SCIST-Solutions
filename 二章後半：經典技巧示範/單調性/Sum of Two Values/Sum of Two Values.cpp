#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	
	return a.s < b.s;
	
}

int main(){
	
	int n, tar;
	
	cin >> n >> tar;
	
	pair<int, int> a[n];
	for(int i=0;i<n;i++){
		
		int x;
		cin >> x;
		
		a[i] = make_pair(i, x);
		
	}
		
	sort(a, a+n, cmp);
	
	bool found = false;
	int i, j;
	
	for(i=0, j=n-1;i<n;i++){
		
		for(;j>i && a[i].s+a[j].s>tar;j--);
		
		if(i != j && a[i].s+a[j].s == tar){
			
			if(a[i].f > a[j].f)
				cout << a[j].f+1 << " " << a[i].f+1;
			else
				cout << a[i].f+1 << " " << a[j].f+1;
			found = true;
			break;
			
		}
		
	}
	
	if(!found)
		cout << "IMPOSSIBLE";
	
	
	return 0;
}