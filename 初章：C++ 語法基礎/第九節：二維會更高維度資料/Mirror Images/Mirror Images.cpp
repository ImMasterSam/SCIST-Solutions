#include<iostream>
using namespace std;

char a[55][55];

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, r, c;
	cin >> t;
	
	for(int times=1;times<=t;times++){
		
		cin >> r >> c;
		
		cout << "Test " << times << "\n";
		
		for(int i=0;i<r;i++)
			cin >> a[i];
	
		
		for(int i=r-1;i>=0;i--){
			for(int j=c-1;j>=0;j--)
				cout << a[i][j];
			cout << "\n";
		}
		
	}
	
	
	return 0;
}