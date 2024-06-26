#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const long long g = 34943;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		if(s == "#")
			break;
		
		long long bin = 0, crc;
		
		for(int i=0;i<(int)s.size();i++){
			
			bin += s[i];
			
			bin *= pow(2, 8);
			
			bin %= g;
			
		}
		
		bin *= pow(2, 8);
			
		bin %= g;
		
		if(bin == 0)
			crc = 0;
		else
			crc = g-bin;
			
		//cout << hex << crc << dec << "\n";
		
		char alpha[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
		char hex[4];
		
		for(int i=0;i<4;i++){
			
			hex[i] = alpha[crc%16];
			crc /= 16;
			
		}
		
		for(int i=3;i>=0;i--){
			
			cout << hex[i];
			
			if(i == 2)
				cout << " ";
			
		}
		
		cout << "\n";
		
	}
	
	
	return 0;
}