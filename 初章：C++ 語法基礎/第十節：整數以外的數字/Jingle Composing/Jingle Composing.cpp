#include<iostream>
using namespace std;

int main(){
	
	string s;
	cin >> s;
	
	while(s != "*"){
		
		int sum = 0, count = 0;
		
		for(int i=1;i<(int)s.size();i++){
			
			if(s[i] == '/'){
				if(sum == 64)
					count++;
				sum = 0;
				continue;
			}
			
			if(s[i] == 'W')
				sum += 64;
			else if(s[i] == 'H')
				sum += 32;
			else if(s[i] == 'Q')
				sum += 16;
			else if(s[i] == 'E')
				sum += 8;
			else if(s[i] == 'S')
				sum += 4;
			else if(s[i] == 'T')
				sum += 2;
			else if(s[i] == 'X')
				sum += 1;
			
		}
		
		cout << count << "\n";
		cin >> s;
		
	}
	
	return 0;
}