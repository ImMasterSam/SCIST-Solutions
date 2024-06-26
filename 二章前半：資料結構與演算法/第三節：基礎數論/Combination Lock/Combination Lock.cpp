#include<iostream>
using namespace std;

#define min(a, b) ((a<b)?a:b)

int main(){
	
	int a, b, c, d;
	
	
	while(cin >> a >> b >> c >> d){
		
		if(a==0 && b==0 && c==0 && d==0)
			break;
			
		int deg = 0;
		
		deg += 720;
	
		deg += (a-b+40)%40 * 9;
		
		deg += 360;
		
		deg += (c-b+40)%40 * 9;
		
		deg += (c-d+40)%40 * 9;
		
		cout << deg << "\n";
		
	}
	
	
	return 0;
}