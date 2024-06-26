#include<iostream>
using namespace std;

int main(){
	
	long long n, x, b_pos;
	
	cin >> n;
	
	long long a[n+1], sum=0;
	a[0] = 0;
	
	for(int i=1;i<=n;i++){
		
		cin >> x;
		
		if(x == 0)
			b_pos = i;
		
		a[i] = x + a[i-1];
		
		sum += x*i;
		
	}
	
	long long max = sum;
	
	for(int i=1;i<=n;i++){
		
		long long temp = sum;
		
		if(i<b_pos)
			temp += a[b_pos-1]-a[i-1];
		
		else if(i>b_pos)
			temp -= a[i]-a[b_pos];
		else
			continue;
		
		if(temp > max)
			max = temp;
			
		//cout << temp << "\n";
		
	}
	
	cout << max;
	
	return 0;
}