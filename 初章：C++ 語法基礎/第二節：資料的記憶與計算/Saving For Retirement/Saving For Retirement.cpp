#include<iostream>
using namespace std;

int main(){
	
	int b, br, bs, a, as;
	cin >>  b >> br >> bs >> a >> as;
	
	int s = (br-b)*bs;
	
	cout << a + s/as + 1;
	
	return 0;
}