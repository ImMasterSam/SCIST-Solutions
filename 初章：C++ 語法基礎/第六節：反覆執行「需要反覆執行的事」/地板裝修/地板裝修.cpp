#include<iostream>
using namespace std;

int main(){
	
	int n, k;
	cin >> n >> k;
	
	for(int i=0;i<n*k;i++){
		
		for(int j=0;j<n*k;j++){
			
			if((i/k)%2==0){
				if((j/k)%2==0)
					cout << '*';
				else
					cout << ' ';
			}
			
			else{
				if((j/k)%2==1)
					cout << '*';
				else
					cout << ' ';
			}
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}