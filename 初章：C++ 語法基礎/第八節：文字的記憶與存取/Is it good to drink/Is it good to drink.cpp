#include<iostream>
using namespace std;

int main(){
	
	string A, B, a, b;
	cin >> A >> a;
	cin >> B >> b;
	
	if(a==b){
		
		if(A==B)
			cout << "GOOD\n";
		else
			cout << "=~=\n";
		
	}
	else{
		
		if(A==B)
			cout << "=~=\n";
		else
			cout << "OTZ\n";
		
	}
	
	return 0;
}