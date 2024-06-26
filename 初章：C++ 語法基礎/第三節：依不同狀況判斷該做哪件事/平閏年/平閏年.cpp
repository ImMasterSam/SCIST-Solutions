#include <iostream>
using namespace std;

bool isleap(int y){
	
	bool i = false;
	
	if(y%4==0){
		if(y%100==0){
			if(y%400==0)
				i = true;
		}
		else
			i = true;
	}
	
	return i;
	
}

int main(){
	
	int Y;
	cin >> Y;
	
	if(isleap(Y))
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}