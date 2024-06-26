#include<iostream>
#include<sstream>
using namespace std;

int main(){
	
	string s;
	int num;
	
	while(cin >> s){
		
		int cnt = sscanf(s.c_str(), "0x%X", &num);
		
		if(cnt == 1){
			
			printf("%d\n", num);
			continue;
			
		}
		
		sscanf(s.c_str(), "%d", &num);
		if(num<0)
			break;
		printf("0x%X\n", num);
		
	}
	
	
	return 0;
}