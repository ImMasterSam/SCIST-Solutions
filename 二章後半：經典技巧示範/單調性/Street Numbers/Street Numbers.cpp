#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
	int count = 0;
	
	long long left = 1;
	long long right = 3;
	int i=2, j=3;
	
	while(count < 10){
		
		//cout << left << " : " << right << "\n";
		
		if(right == left){
			
			count++;
			cout << setw(10) << i << setw(10) << j << "\n";
			left += i;
			right -= (i+1);
			i++;
			
		}
		
		if(right > left){
			
			left += i;
			right -= (i+1);
			i++;
			
		}
		
		else{
			
			j++;
			right += j;
			
		}
		
	}
	
	return 0;
}