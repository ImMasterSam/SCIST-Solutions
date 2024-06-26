#include <iostream>
using namespace std;

int add(int a, int b){
	
	int res = 0;
	
	while((a&b)){
		
		int t = a^b;
		a = (a&b) << 1;
		b = t;
		
	}
	
	res = (a|b);
	
	return res;
}

int main(){
	
	cout << add(15, 5);
	
	return 0;
}