#include <iostream>
using namespace std;

int main(){
	int x, y;
	int a, b;
	cin >> x >> y;
	
	a = (x+y)/2;
	b = x-a;
	
	printf("a: %d, b: %d\n", a, b);
	return 0;
}

