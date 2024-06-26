#include <iostream>
using namespace std;

int main(){
	int a, b, h, count=0;
	cin >> a >> b >> h;
	while(h>0){
		h -= a;
		count++;
		if(h<=0)
			break;
		else
			h += b;
	}
	
	cout << count << "\n";
	
	return 0;
}

