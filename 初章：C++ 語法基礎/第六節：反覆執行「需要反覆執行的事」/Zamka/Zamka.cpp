#include <iostream>
using namespace std;

int main(){
	long long l, d,x, temp_num, nums, min=100001, max=-1;
	cin >> l >> d >> x;
	
	for(int i=l;i<=d;i++){
		temp_num = i;
		nums = 0;
		
		while(temp_num >0){
			nums += temp_num%10;
			temp_num /= 10;
		}
		
		if(nums == x){
			if(i > max)
				max = i;
			if (i < min)
				min = i;
		}	
		
	}
	
	cout << min << "\n" << max << "\n";
	
	return 0;
}

