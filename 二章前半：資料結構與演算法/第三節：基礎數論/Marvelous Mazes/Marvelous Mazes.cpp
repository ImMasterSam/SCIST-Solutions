#include<iostream>
using namespace std;

int main(){
	
	string s;
	
	while(getline(cin, s)){
		
		if(s == "")
			cout << "\n";
			
		else{
			
			int sum = 0;
			
			for(int i=0;i<(int)s.size();i++){
				
				if(s[i] == 'b'){
					
					for(int j=0;j<sum;j++)
						cout << ' ';
						
					sum = 0;
					
				}
				
				else if(s[i] == '!')
					cout << '\n';
				
				else if(s[i]>='0'&&s[i]<='9'){
					
					sum += s[i] - '0';
					
				}
				
				else{
					
					for(int j=0;j<sum;j++)
						cout << s[i];
						
					sum = 0;
					
				}
				
			}
			
			cout << "\n";
			
		}
		
	}
	
	return 0;
}