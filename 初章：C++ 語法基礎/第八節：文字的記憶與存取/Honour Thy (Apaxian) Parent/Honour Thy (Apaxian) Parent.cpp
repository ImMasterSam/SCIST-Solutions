#include<iostream>
using namespace std;

int main(){
	
	string y, p;
	cin >> y >> p;
	
	if(y[y.size()-1]=='e')
		cout << y << "x" << p;
	else if(y[y.size()-2]=='e'||y[y.size()-1]=='x')
		cout << y << p;
	else if(y[y.size()-1]=='a'||y[y.size()-1]=='i'||y[y.size()-1]=='o'||y[y.size()-1]=='u')
		cout << y.substr(0, y.size()-1) << "ex" << p;
	else
		cout << y << "ex" << p;
		
	return 0;
}