#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			printf("%2dx%2d = %2d", j, i, i*j);
			
			if(j!=n)
				cout << ", ";
		}
		
		cout << "\n";
	}
	return 0;
}

