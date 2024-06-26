#include <iostream>
using namespace std;

int main(){
	long long n, t1, t2, time=0;
	cin >> n;
	
	if(n%2)
		cout << "still running\n";
		
	else{
		for(int i=0;i<n/2;i++){
			cin >> t1;
			cin >> t2;
			time += (t2-t1);
		}
		
		cout << time << "\n";
	}
	
	
	return 0;
}

