#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long t, a, f;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> a >> f;
		
		for(int j=0;j<f;j++){
			for(int k=0;k<2*a;k++){
				for(int l=0;l<a-abs(k-a);l++)
					cout << a-abs(k-a);
				cout << "\n";
			}

		}
		
	}
	
	return 0;
}

