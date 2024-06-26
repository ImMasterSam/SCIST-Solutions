#include <iostream>
using namespace std;

int main(){
	int n, l=0, pre;
	bool s=true;
	
	cin >> n;
	pre = n%10;
	
	while(n){
		if(n%10!=pre)
			s = false;
		n /= 10;
		l++;
	}
	
	if(l==4 && s)
		cout << "GREAT!!\n";
	else
		cout << "OAQ\n";
	
	return 0;
}

