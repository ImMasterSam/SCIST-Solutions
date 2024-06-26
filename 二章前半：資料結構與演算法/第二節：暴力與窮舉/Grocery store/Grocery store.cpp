#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double ESP = 1e-7;

int main(){
	
	long long a, b, c, d;
	
	cout << fixed << setprecision(2);
	
	for(a=1;4*a<=2000;a++){
		
		for(b=a;a+3*b<=2000;b++){
			
			for(c=b;a+b+2*c<=2000;c++){
				
				long long p = a*b*c;
				long long s = a+b+c;
				
				if (p <= 1000000)
					continue;
				
		        if ((s * 1000000) % (p - 1000000))
		        	continue;
					
				d = (s * 1000000) / (p - 1000000);
				s += d;
				
				//cout << a/100.0 << " " << b/100.0 << " " << c/100.0 << "\n";
					
				if(s>2000 || d<c)
					continue;
	
				
				cout << a/100.0 << " " << b/100.0 << " " << c/100.0 << " " << d/100.0 << "\n";
				
			}
			
		}
		
	}
	
	
	return 0;
}