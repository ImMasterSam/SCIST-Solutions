#include <bits/stdc++.h>
using namespace std;

bool check(unsigned int c, unsigned int d){
	
	for(int i=0;i<31;i++){
		
		if((c & (1 << i)) > (d & (1 << i)))
			return false;
		
	}
	
	return true;
	
}

int main(){
	
	int t;
	cin >> t;
	
	unsigned int a, b, c, d;
	int pos;
	
	while(t--){
		
		cin >> c >> d;
		
		if(!check(c, d))
			cout << "-1\n";
		
		else{
			
			a = c; b = c;
			
			d &= ~(c & d);
			
			pos = 0;
			
			while(d){
				
				if(d == 1)
					b += (1 << pos);
				else if (d&1)
					a += (1 << pos);
					
				pos++;
				d >>= 1;
				
			}
			
			cout << a << " " << b << "\n"; 
			
		}
		
	}
		
	return 0;
}