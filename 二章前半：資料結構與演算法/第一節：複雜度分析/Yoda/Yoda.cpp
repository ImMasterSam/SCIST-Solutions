#include<iostream>
using namespace std;

int main(){
	
	string a, b;
	
	cin >> a >> b;
	
	int ml = max(a.size(), b.size());
	
	int used_a[a.size()] = {0}, used_b[b.size()] = {0};
	
	bool a_zero = true, a_yoda = true;
	bool b_zero = true, b_yoda = true;
	
	for(int i=0;i<ml;i++){
		
		if(i>=a.size()){
			used_b[b.size()-i-1]++;
			b_yoda = false;
			if(b[b.size()-i-1] > '0')
				b_zero = false;
		}
		else if(i>=b.size()){
			used_a[a.size()-i-1]++;
			a_yoda = false;
			if(a[a.size()-i-1] > '0')
				a_zero = false;
		}
			
		else{
			
			if(a[a.size()-i-1]>b[b.size()-i-1]){
				used_a[a.size()-i-1]++;
				a_yoda = false;
				if(a[a.size()-i-1] > '0')
					a_zero = false;
			}
			else if(a[a.size()-i-1]<b[b.size()-i-1]){
				used_b[b.size()-i-1]++;
				b_yoda = false;
				if(b[b.size()-i-1] > '0')
					b_zero = false;
				
			}
			else{
				used_a[a.size()-i-1]++;
				a_yoda = false;
				if(a[a.size()-i-1] > '0')
					a_zero = false;
				used_b[b.size()-i-1]++;
				b_yoda = false;
				if(b[b.size()-i-1] > '0')
					b_zero = false;
			}			
		}
	}
	
	if(a_yoda){
		cout << "YODA";
	}
	else if (a_zero){
		cout << "0";
	}
	else{
		for(int i=0;i<a.size();i++){
			if(used_a[i])
				cout << a[i];
		}
	}
		
	cout << "\n";
	
	if(b_yoda){
		cout << "YODA";
	}
	else if (b_zero){
		cout << "0";
	}
	else{
		for(int i=0;i<b.size();i++){
			if(used_b[i])
				cout << b[i];
		}
	}	
		
	return 0;
}