#include<iostream>
using namespace std;

int main(){
	
	int n;
	
	while(cin >> n){
		
		int t = n;
		int level=1;
		
		while(t-level>0){
			t -= level;
			level++;
		}
		
		int pos = t;
		
		//cout << level << " " << pos << "\n";
		
		if(level%2){
			cout << "TERM " << n << " IS " << (level+1)-pos << "/" << pos << "\n";
		}
		
		else{
			cout << "TERM " << n << " IS " << pos << "/" << (level+1)-pos << "\n";
		}
		
	}
	
	return 0;
}