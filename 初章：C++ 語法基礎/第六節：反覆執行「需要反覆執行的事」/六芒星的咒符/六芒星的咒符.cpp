#include <iostream>
using namespace std;

int main(){
	long long t, n;
	cin >> t;
	
	for(int k=0;k<t;k++){
		cin >> n;
		
		for(int i=0;i<n-3;i++){
			
			for(int j=0;j<n-i-1;j++)
				cout << " ";
			
			for(int j=0;j<2*i+1;j++)
				cout << "*";
			
			cout << "\n";
		}
		
		for(int i=0;i<2*n-1;i++)
			cout << "*";
			
		cout << "\n ";
		for(int i=0;i<2*n-3;i++)
			cout << "*";
		cout << "\n";
		
		for(int i=0;i<2*n-1;i++)
			cout << "*";
		cout << "\n";
		
		for(int i=n-4;i>=0;i--){
			
			for(int j=0;j<n-i-1;j++)
				cout << " ";
			
			for(int j=0;j<2*i+1;j++)
				cout << "*";
			
			cout << "\n";
		}
		
	}
	
	return 0;
}

