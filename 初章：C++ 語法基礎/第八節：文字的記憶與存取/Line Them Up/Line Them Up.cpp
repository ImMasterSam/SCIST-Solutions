#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string now, pre;
	cin >> pre;
	
	bool inc = true, dec = true;
	
	for(int i=0;i<n-1;i++){
		
		cin >> now;
		
		if(now < pre)
			inc = false;
		
		if(now > pre)
			dec = false;
			
		pre = now;
		
	}
	
	if(inc)
		cout << "INCREASING";
	else if (dec)
		cout << "DECREASING";
	else
		cout << "NEITHER";
	
		
	return 0;
}