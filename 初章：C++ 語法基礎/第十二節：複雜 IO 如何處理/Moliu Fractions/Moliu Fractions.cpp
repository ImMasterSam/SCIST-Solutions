#include<iostream>
#include<sstream>
using namespace std;

int gcd(int a, int b){
	
	int t;
	
	if(a<b){
		t = a;
		a = b;
		b = t;
	}
	
	while(a%b != 0){
		t = a%b;
		a = b;
		b = t;
	}
	
	return b;
}

int main(){
	
	char s[2000000];
	int t;
	cin >> t;
	
	cin.ignore();
	
	for(int time=0;time<t;time++){
		
		long long up = 1, down = 1;
		
		s[0] = ' ';
		fgets(s+1, sizeof(s) - 1, stdin);
		
		int pos;
		const char* ptr = s;
		
		char buf[128];
		
		while(true){
			
			//cout << "-> " << ptr << "\n";
			
			int res = sscanf(ptr, "%*[^0-9]%[^ ]%n", buf, &pos);
			
			if(res == -1)
				break;
				
			ptr += pos;
			
			int a, b, c;
			
			int cnt = sscanf(buf, "%d%*c%d%*c%d", &a, &b, &c);
			
			if(cnt == 1){
				up *= a;
			}
			else if(cnt == 2){
				up *= a;
				down *= b;
			}
			else{
				up *= a*c + b;
				down *= c;
			}
						
		}
		
		//cout << "debug1: " << up << " / " << down << endl;
		
		if(up == 0){
			
			cout << "0\n";
			continue;
			
		}
		
		int g = (up != 0 && down != 0) ? gcd(up, down) : 1;
		
		up = up / g;
		down = down / g;
		
		//cout << "debug2: " << up << " / " << down << endl;
		
		int carry = up/down;
		up %= down;
		
		g = (up != 0 && down != 0) ? gcd(up, down) : 1;
		up = up / g;
		down = down / g;
		
		if(carry > 0){
			cout << carry;
		}
		
		if(up != 0){
			
			if(carry != 0)
				cout << "-";
				
			cout << up << "/" << down;
			
		}
		
		cout << "\n";
		
		//cin.ignore();
		
	}
		
	return 0;
}