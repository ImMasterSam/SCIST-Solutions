#include <iostream>
using namespace std;

long long a[200005] = {0};

int main(){
	
	long long n, k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	int i=0, j=0;
	long long sum=0;
	
	int count = 0;
	
	for(j = 0; j < n; j++){
		
        sum += a[j];
        
        while(sum > k)
            sum -= a[i++];
            
        if(sum == k)count++;
    }
	
	cout << count;
	
	return 0;
}