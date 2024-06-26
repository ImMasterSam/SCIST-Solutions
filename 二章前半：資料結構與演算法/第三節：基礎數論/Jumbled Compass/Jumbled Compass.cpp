#include<iostream>
using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	
	int counter = (b-a+360)%360;
	int clock = (a-b+360)%360;
	
	if(counter == 180 && clock == 180)
		cout << 180;
	else
		cout << ((counter < clock) ? (b-a+360)%360 : -(a-b+360)%360);
	
	return 0;
}