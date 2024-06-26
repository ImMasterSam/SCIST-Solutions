#include<iostream>
using namespace std;

#define max(a, b) a>b?a:b

int main(){
	
	int n, md=0, min = 1000;
	cin >> n;
	
	int t[n];
	
	for(int i=0;i<n;i++)
		cin >> t[i];
		
	for(int i=0;i<n-2;i++){
		
		if( (max(t[i], t[i+2])) < min){
			min = max(t[i], t[i+2]);
			md = i+1;
		}
		
	}
	
	cout << md << " " << min;
	
		
	return 0;
}