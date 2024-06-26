#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	int n;
	int arr[201] = {0};
	char secret[201][201] = {0};
	char ws;
	string s;
	long long k;
	
	while(cin >> n, n){
		
		for(int i=0;i<n;i++)
			cin >> arr[i];
		
		while(cin >> k){
			
			if(k == 0)
				break;
				
			//cout << "K: " << k << "\n";
			
			cin.ignore();
			getline(cin, s);
			
			//cout << "input: " << s << "\n";
			
			for(int i=0;i<n;i++){
				
				if(i>=(int)s.size()){
					
					secret[0][i] = ' ';
					
				}
				else{
					
					secret[0][i] = s[i];
					
				}
					
			}
			
			secret[0][n] = '\0';
			
			//cout << "\nProblem:" << s << "\n";
			
			int rep = 0;
			
			for(int i=1;i<n+1;i++){
				
				for(int j=0;j<n;j++){
					
					secret[i][arr[j]-1] = secret[i-1][j]; 
					
				}
				
				secret[i][n] = '\0';
				
				//cout << secret[i] << "\n";
				
				//cout << i << ": " << strcmp(secret[i], secret[0]) << "\n";
				
				if(strcmp(secret[i], secret[0]) == 0){
					//cout << "check\n";
					rep = i;
					break;
				}
				
			}
			
			/*
			for(int i=0;i<n;i++)
				cout << secret[i] << "\n";*/
				
			cout << secret[k%rep] << "\n";
			
			
		}
		
		cout << "\n";
		
	}
	
	return 0;
}