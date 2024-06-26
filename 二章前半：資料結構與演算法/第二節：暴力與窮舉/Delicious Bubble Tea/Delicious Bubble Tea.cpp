#include<iostream>
#include<climits>
using namespace std;

int main(){
	
	int n, m, t, in;
	long long tea_price[1005], topin_price[1005];
	
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> tea_price[i];
		
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> topin_price[i];
		
	long long cheapest = LLONG_MAX-1;
		
	for(int i=0;i<n;i++){
		
		cin >> t;
		
		for(int j=0;j<t;j++){
			
			cin >> in;
			in--;
			
			if(tea_price[i]+topin_price[in]<cheapest)
				cheapest = tea_price[i]+topin_price[in];
			
		}
		
	}
	
	long long money;
	
	cin >> money;
	
	if(money/cheapest == 0)
		cout << 0;
	else
		cout << money/cheapest - 1;
	
	
	return 0;
}