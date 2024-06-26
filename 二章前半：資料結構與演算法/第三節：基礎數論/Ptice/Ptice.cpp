#include<iostream>
using namespace std;

int main(){
	
	int l;
	string s;
	
	cin >> l >> s;
	
	int correct[3] = {0};
	int guess[3][6] = {{0, 1, 2}, {1, 0, 1, 2}, {2, 2, 0, 0, 1, 1}};
	int max = 0;
	
	for(int i=0;i<l;i++){
		
		int ans = s[i] - 'A';
		
		if(ans == guess[0][i%3]){
			correct[0]++;
			if(correct[0] > max)
				max = correct[0];
		}
		
		if(ans == guess[1][i%4]){
			correct[1]++;
			if(correct[1] > max)
				max = correct[1];
		}
		
		if(ans == guess[2][i%6]){
			correct[2]++;
			if(correct[2] > max)
				max = correct[2];
		}
		
	}
	
	cout << max << "\n";
	
	for(int i=0;i<3;i++){
		
		if(correct[i] == max){
			
			switch(i){
				
				case 0:
					cout << "Adrian\n";
					break;
					
				case 1:
					cout << "Bruno\n";
					break;
					
				case 2:
					cout << "Goran\n";
					break;
				
			}
			
		}
		
	}
	
	return 0;
}