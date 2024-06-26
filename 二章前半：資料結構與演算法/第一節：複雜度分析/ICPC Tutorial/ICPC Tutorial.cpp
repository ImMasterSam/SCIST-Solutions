#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	double m, n, times;
	int t;
	
	cin >> m >> n >> t;
	
	if(t == 1){
		
		times = 1;
		for(int i=2;i<=n;i++){
			times *= i;
			if(times > m){
				times = m+1;
				break;
			}
		}

	}
	else if(t == 2){
		times = pow(2, n);
	}
	else if(t == 3){
		times = pow(n, 4);
	}
	else if(t == 4){
		times = pow(n, 3);
	}
	else if(t == 5){
		times = pow(n, 2);
	}
	else if(t == 6){
		times = log2(n);
		times *= n;
	}
	else if(t == 7){
		times = n;
	}
	
	if(times <= m)
		cout << "AC";
	else
		cout << "TLE";
		
	return 0;
}