#include<iostream>
using namespace std;

int main(){
	
	int x, sum;
	int index = 0, max = 0;
	
	for(int i=0;i<5;i++){
		
		sum = 0;
		
		for(int j=0;j<4;j++){
			
			cin >> x;
			sum += x;
			
		}
		
		if(sum > max){
			
			max = sum;
			index = i;
			
		}
		
	}
	
	cout << index+1 << " " << max;
		
	return 0;
}