#include <iostream>
using namespace std;

int main(){
	int s, t, n;;
	while(cin >> s >> t >> n){
		if(s == 0 && t==0 && n==0)
			break;
			
		else{
			for(int i=0;i<t;i++){
				for(int j=0;j<(n+1)*t+n*s;j++)
					cout << "*";
				cout << "\n";
			}
			
			for(int i=0;i<n;i++){
				for(int j=0;j<s;j++){
					for(int k=0;k<t;k++)
						cout << "*";
					for(int k=0;k<n;k++){
						for(int l=0;l<s;l++)
							cout << ".";
						for(int l=0;l<t;l++)
							cout << "*";
					}
					cout << "\n";
				}
				for(int i=0;i<t;i++){
					for(int j=0;j<(n+1)*t+n*s;j++)
						cout << "*";
					cout << "\n";
				}
			}
			
		}
		
	}
	
	return 0;
}

