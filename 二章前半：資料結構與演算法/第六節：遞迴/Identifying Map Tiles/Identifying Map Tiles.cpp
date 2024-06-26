#include<iostream>
using namespace std;

int main(){
	
	string s;
	
	cin >> s;
	
	cout << s.size() << " ";
	
	int x=0, y=0;
	
	for(int i=0;i<s.size();i++){
		
		x *= 2;
		y *= 2;
		
		switch(s[i]){
			
			case '1':
				x++;
				break;
			case '2':
				y++;
				break;
			case '3':
				x++;
				y++;
				break;
			
		}
		
	}
	
	cout << x << " " << y;
	
	return 0;
}