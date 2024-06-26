#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	
	double n, p;
	
	while(cin >> n >> p){
		
		cout << fixed << setprecision(0) << pow(10, log10(p)/n) << "\n";
		
	}
		
	return 0;
}