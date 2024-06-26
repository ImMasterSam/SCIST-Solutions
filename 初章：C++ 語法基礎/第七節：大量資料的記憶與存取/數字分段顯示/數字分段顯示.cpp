#include<iostream>
using namespace std;

int main(){
	
	string a;
	int c;
	cin >> a;
	c = a.length();
	
	for(int i = 0;i<a.length();i++){

		cout << a[i];
		c -= 1;
		if(c%3==0 &&  i!=a.length()-1){
			cout << ",";
		}
		
		
	}
	
	return 0;
}