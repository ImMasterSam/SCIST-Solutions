#include<iostream>
#include<cmath>
using namespace std;

int power_sum(int a, int b){
	
	int sum = 0;
	
	for(int i=0;i<=b;i++){
		
		sum += pow(a, i);
		
	}
	
	return sum;
	
}

int main(){
	
	int a, b;
	cin >> a >> b;
	
	cout << power_sum(a, b);
	
	return 0;
}