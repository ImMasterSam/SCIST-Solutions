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
	
	string s;
	int t;
	cin >> t;
	
	cin.ignore();
	
	for(int time=0;time<t;time++){
		
		long long up = 1, down = 1;
		
		getline(cin, s);
		
		int pos;
		const char* ptr = s.c_str();
		
		char buf[128];
		
		while(true){
			
			int res = sscanf(ptr, "%*[^0-9]%[^ ]%n", buf, &pos);
			
			if(res == -1)
				break;
				
			ptr += pos;
			
			int a, b, c;
			
			int cnt = sscanf(buf, "%d%*[^0-9]%d%*[^0-9]%d", &a, &b, &c);
			
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
		
		int g = (down != 0) ? gcd(up, down) : up;
		
		//cout << up << "/" << down << "\n";
		
		
		if(up > down){
			cout << up/down << "-";
		}
		
		cout << (up/g)%(down/g) << "/" << down/g << "\n";
		
		//cin.ignore();
		
	}
		
	return 0;
}