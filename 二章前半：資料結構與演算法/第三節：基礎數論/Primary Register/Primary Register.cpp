#include<iostream>
using namespace std;

int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};

int main(){
	
	int nums[8] = {0};
	
	for(int i=0;i<8;i++)
		cin >> nums[i];
		
	bool crash = false;
	int count = 0;
	
	while(!crash){
		
		int idx = 0;
		count++;
		nums[idx]++;
		/*
		for(int i=0;i<8;i++)
			cout << nums[i] << " ";
		cout << "\n";*/
		
		
		while(nums[idx] >= primes[idx]){
			
			if(idx == 7){
				crash = true;
				break;
			}
			
			nums[idx] %= primes[idx];
			nums[idx+1]++;
			idx++;
			
		}
		
	}
	
	cout << count-1;
	
	return 0;
}