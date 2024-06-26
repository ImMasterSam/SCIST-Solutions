#include<iostream>
using namespace std;

int main(){
	
	string a, b;
	
	cin >> a >> b;
	
	int x, y;
	
	bool found = false;
	
	for(int i=0;i<a.size() && !found;i++){
		
		for(int j=0;j<b.size() && !found;j++){
			
			if(a[i] == b[j]){
				
				x = j;
				y = i;
				found = true;
				
			}
			
		}
		
	}
	
	int index_a = 0, index_b = 0;
	
	for(int i=0;i<b.size();i++){
		
		for(int j=0;j<a.size();j++){
			
			if(i == x){
				
				cout << a[index_a++];
				if(j ==  y) index_b++;
				
			}
			
			else if (j ==  y){
				
				cout << b[index_b++];
				
			}
			
			else
				
				cout << ".";
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}