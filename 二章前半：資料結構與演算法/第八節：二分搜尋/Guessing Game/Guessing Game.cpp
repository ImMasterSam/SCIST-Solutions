#include <iostream>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n, n){
		
		int high[11] = {0};
		int low[11] = {0};
		
		while(1){
			
			cin.ignore();
			
			string s;
			getline(cin, s);
			
			if(s == "right on")
				break;
			
			if(s == "too high")
				high[n]++;
			else if(s == "too low")
				low[n]++;
			
			cin >> n;
			
		}
		
		bool cheat = false;
		
		for(int i=n;i<=10;i++){
			
			if(low[i])
				cheat = true;
			
		}
		
		for(int i=0;i<=n;i++){
			
			if(high[i])
				cheat = true;
			
		}
		
		cout << (cheat ? "Stan is dishonest\n" : "Stan may be honest\n");
		
	}
	
	return 0;
}