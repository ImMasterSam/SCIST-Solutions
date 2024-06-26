#include<iostream>
using namespace std;

string s;

void dfs(int coe[], int n, int k){
	
	int op = 0;
	
	while(cin >> s && s != "END"){
		
		if(s == "LOOP"){
			
			cin >> s;
			if(s == "n"){
				
				dfs(coe, n+1, k);
				
			}
			else{
				
				int x;
				sscanf(s.c_str(), "%d", &x);
				dfs(coe, n, x*k);
				
			}
			
		}
		else if (s == "OP"){
			
			int x;
			cin >> x;
			op += x;
			
		}
		
	}
	
	coe[n] += op * k;
	
}

int main(){
	
	int t;
	cin >> t;
	
	for(int time=0;time<t;time++){
		
		cin >> s;
		int coe[15] = {0};
		
		dfs(coe, 0, 1);
		
		bool first = true;
		bool zero = true;
		
		cout << "Program #" << time+1 << "\nRuntime = ";
		
		
		for(int i=14;i>=0;i--){
				
			if(coe[i]){
				
				zero = false;
				
				if(!first)
					cout << "+";
				
				if(coe[i]>=2 || i==0){
					
					cout << coe[i];
					if(i>0)
						cout << "*";
					
				}
					
			
				if(i)
					cout << "n";
				
				if(i >= 2)
					cout << "^" << i;
				
				first = false;
				
			}
			
		}
		
		if(zero)
			cout << "0";
		
		cout << "\n\n";
		
	}
	
	return 0;
}