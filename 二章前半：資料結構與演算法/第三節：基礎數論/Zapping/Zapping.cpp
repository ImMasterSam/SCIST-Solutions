#include<iostream>
using namespace std;

#define min(a, b) ((a<b)? a : b )

int main(){
	
	int a, b;
	
	while(cin >> a >> b){
		
		if(a==-1 && b==-1)
			break;
			
		if(a>b){
			
			int t = a;
			a = b;
			b = t;
			
		}
			
		cout << min((b-a), a+(100-b)) << "\n";
		
	}
	
	return 0;
}