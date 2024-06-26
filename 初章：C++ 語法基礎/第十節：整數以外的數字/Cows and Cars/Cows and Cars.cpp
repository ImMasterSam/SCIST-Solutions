#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	
	double car, cow, show;
	
	cout << fixed << setprecision(5);
	
	while(cin >> cow >> car >> show){
		
		double t = cow + car;
		
		double pa1, pa2;
		double pb1, pb2;
		double chance;
		
		pa1 = car/t;
		//cout << pa1 << "\n";
		pa2 = (car-1.0)/(t-show-1.0);
		//cout << pa2 << "\n";
		
		pb1 = cow/t;
		//cout << pb1 << "\n";
		pb2 = car/(t-show-1.0);
		//cout << pb2 << "\n";
		
		chance = pa1*pa2 + pb1*pb2;
		
		cout << chance << "\n";
		
	}
		
	return 0;
}