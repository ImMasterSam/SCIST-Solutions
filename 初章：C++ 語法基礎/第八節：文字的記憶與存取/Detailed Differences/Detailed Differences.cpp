#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	string a, b;
	
	for(int i=0;i<n;i++){
		
		cin >> a >> b;
		
		cout << a << "\n" << b << "\n";
		
		for(int j=0;j<a.size();j++){
			
			if(a[j]!=b[j])
				cout << '*';
			else
				cout << ".";
			
		}
		cout << "\n\n";
		
	}
		
	return 0;
}