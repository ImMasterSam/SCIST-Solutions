#include<iostream>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int d, m;
		cin >> d >> m;
		
		int months[m] = {0};
		for(int i=0;i<m;i++)
			cin >> months[i];
			
		int sum = 0;
		int count_13th = 0;
		
		for(int i=0;i<m;i++){
			
			sum += 12;
			
			if(sum%7 == 5 && months[i] >= 13)
				count_13th++;
				
			sum += months[i]-12;
			
		}
		
		cout << count_13th << "\n";
		
	}
	
	return 0;
}