#include<iostream>
using namespace std;

int main(){
	
	int n, h, w, input;
	cin >> n >> h >> w;
	
	for(int i=0;i<n;i++){
		cin >> input;
		
		if(input*input <= h*h+w*w)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
		
	return 0;
}