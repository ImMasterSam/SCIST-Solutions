#include<iostream>
using namespace std;

int main(){
	
	int x, y;
	
	while(cin >> x >> y){
		
		int a = x, b = y;
		
		int max = 0;
		
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}
		
		for(int i=a;i<=b;i++){
			
			int t=i, count=1;
			
			while(t != 1){
				
				count++;
				
				if(t%2)
					t = 3*t+1;
				else
					t /= 2;
				
			}
			
			if(count > max)
				max = count;
			
		}
		
		cout << x << " " << y << " " << max << "\n";
	
	}
	
	return 0;
}