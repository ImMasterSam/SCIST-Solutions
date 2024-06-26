#include <iostream>
using namespace std;

int main(){
	unsigned long long c=299792458;
	
	printf("1 Light-second(LS) is %lld metres.\n", c);
	printf("1 Light-minute(LM) is %lld metres.\n", c*60);
	printf("1 Light-hour(LH) is %lld metres.\n", c*3600);
	printf("1 Light-day(LD) is %lld metres.\n", c*3600*24);
	printf("1 Light-week(LW) is %lld metres.\n", c*3600*24*7);
	printf("1 Light-year(LY) is %lld metres.\n", c*3600*24*365);

	return 0;
}

