#include <iostream>
using namespace std;

int month[13] = {0, 31, 28, 31, 40, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int n;
	cin >> n;
	cout << month[n]; 
	
	return 0;
}

