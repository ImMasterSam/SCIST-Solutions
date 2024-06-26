#include <iostream>
using namespace std;

int main(){
	int x, temp;
	cin >> x;
	
	while(x/10>0){
		temp=1;
		while(x>0){
			if(x%10!=0)temp *= x%10;
			x /= 10;
		}
		x = temp;
	}
	
	cout << x << "\n";
	
	return 0;
}

