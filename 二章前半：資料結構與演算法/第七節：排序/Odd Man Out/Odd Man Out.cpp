#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		int g;
		cin >> g;
		
		int a[g];
		
		for(int i=0;i<g;i++)
			cin >> a[i];
			
		sort(a, a+g);
		
		cout << "Case #" << time+1 << ": " ;
		
		for(int i=0;i<g;i++){
			
			int temp = 0;
			
			if(i && a[i-1] == a[i])
				temp++;
			
			if(i<g-1 && a[i+1] == a[i])
				temp++;
				
			if(!temp){
				
				cout << a[i] << "\n";
				break;
				
			}
			
		}
		
	}
	
	return 0;
}