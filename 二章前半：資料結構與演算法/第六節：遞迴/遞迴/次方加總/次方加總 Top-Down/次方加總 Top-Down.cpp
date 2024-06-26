#include<iostream>
#include<cmath>
using namespace std;

int power_sum(int a, int b, int i){
	
	if(i > b)
		return 0;
	else
		return power_sum(a, b, i+1) + pow(a, i);
	
}

int main(){
	
	int a, b;
	cin >> a >> b;
	
	cout << power_sum(a, b, 0);
	
	return 0;
}