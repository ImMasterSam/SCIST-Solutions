#include<iostream>
#include<climits>
using namespace std;

int main(){
	
	int a, b, c;
	int A, B, C;
	
	int n;
	
	cin >> a >> b >> c;
	cin >> A >> B >> C;
	
	cin >> n;
	
	long long max = LLONG_MIN+1;
	
	
	for(int i=0;i<=n;i++){
		
		int N = n-i;
		
		int y1 = a*i*i+b*i+c;
		int y2 = A*N*N+B*N+C;
		
		if(y1+y2>max)
			max = y1+y2;
		
	}
	
	cout << max;
	
	
	return 0;
}