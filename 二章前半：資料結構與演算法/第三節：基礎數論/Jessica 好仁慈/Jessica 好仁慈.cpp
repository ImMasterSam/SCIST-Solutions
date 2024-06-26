#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long a, b, c, num=0, i=0, ans=0;
	int nums[40]={0};
	cin >> a >> b >> c;
	if(c==0)
		cout << "0\n";
	else{
		while(c>0){
			num += (c%10)*pow(a, i);
			i++;
			c /= 10;
		}
		
		i=0;
		while(num>0){
			nums[i] = num%b;
			num /= b;
			i++;
		}
		
		for(i;i>0;i--)
			cout << nums[i-1];
		cout << "\n";
	}
	
	return 0;
}

