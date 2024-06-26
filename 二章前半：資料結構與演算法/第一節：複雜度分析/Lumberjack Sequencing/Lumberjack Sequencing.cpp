#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	cout << "Lumberjacks:\n";
	
	for(int time=0;time<n;time++){
		
		int pre, now;
		cin >> pre;
		
		bool inc=true, dec=true;
		
		for(int i=1;i<10;i++){
			cin >> now;
			
			if(now-pre > 0)
				dec = false;
			else
				inc = false;
			pre = now;
		}
		
		if(inc||dec)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
		
	}
	
	return 0;
}