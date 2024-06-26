#include<iostream>
using namespace std;

int main(){
	
	int a, b, c, d;
	
	cin >> a >> b;
	cin >> c >> d;
	
	int t1, t2, time;
	
	t1 = a*60+b;
	t2 = c*60+d;
	
	time = (t2-t1+1440)%1440;
	
	cout << "totally " << time/60 << " hours and " << time%60 << " minutes.\n";
	
	return 0;
}