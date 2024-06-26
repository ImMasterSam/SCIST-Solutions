#include<iostream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	long long n;
	cin >> n;
	string num;
	
	for(long long time=0;time<n;time++){
		
		int sum=0;
		
		for(int i=0;i<4;i++){
			cin >> num;
			
			for(int j=0;j<4;j++){
				
				if(j%2)
					sum += num[j]-'0';
				
				else{
					int temp = 2*(num[j]-'0');
					while(temp){
						sum += temp%10;
						temp /= 10;
					}
				}
					
			}
		}
		
		if(sum%10)
			cout << "Invalid\n";
		else
			cout << "Valid\n";
		
	}
	
	return 0;
}