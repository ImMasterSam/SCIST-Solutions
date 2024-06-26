#include<iostream>
using namespace std;

int main(){
	
	int a, b;
	cin >> a >> b;
	
	if(a>0){
		if(b>0){
			cout << "Alloy";
		}
		else{
			cout << "Gold";
		}
	}
	else{
		cout << "Silver";
	}
		
	return 0;
}