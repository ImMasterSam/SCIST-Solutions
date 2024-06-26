#include<iostream>
using namespace std;

char alpha[8] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7'};

int val[8][2] = {{11, 11}, {4, 4}, {3, 3}, {20, 2}, {10, 10}, {14, 0}, {0, 0}, {0, 0}};

int main(){
	
	int n;
	char d;
	
	cin >> n >> d;
	
	string s;
	int sum = 0;
	
	for(int i=0;i<4*n;i++){
		
		cin >> s;
		
		for(int j=0;j<8;j++){
			
			if(s[0] == alpha[j]){
				
				sum += val[j][s[1] != d];
				break;
				
			}
			
		}
		
	}
	
	cout << sum << "\n";
	
	return 0;
}