#include<iostream>
using namespace std;

int main(){
	
	int n, input;
	double play, hit;
	cin >> n;
	
	play = n;
	
	for(int i=0;i<n;i++){
		cin >> input;
		
		if(input == -1)
			play -= 1;
		else
			hit += input;
		
	}
	
	cout << fixed;
	cout.precision(9);
	
	cout << hit/play;
	
	return 0;
}