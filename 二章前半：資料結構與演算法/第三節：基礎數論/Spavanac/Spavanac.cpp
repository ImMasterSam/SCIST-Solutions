#include<iostream>
using namespace std;

int main(){
	
	int h, m;
	
	cin >> h >> m;
	
	if(m<45){
		
		h = (h-1+24)%24;
		
	}
	
	m = (m-45+60)%60;
	
	cout << h << " " << m;
	
	return 0;
}