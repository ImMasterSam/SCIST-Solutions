#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	string s;
	int line = 0;
	
	while(getline(cin, s)){
		
		if(s == "___________"){
			line++;
			
			if(line%2 && line > 1)
				cout << "\n";
				
		}
		else{
			
			int sum = 0;
			int p = 7;
		
			for(int i=1;i<=9;i++){
				
				if(s[i] == 'o')
					sum += (int)pow(2, p);
				
				if(s[i] != '.')
					p--;
				
			}
			cout << (char)sum;
			
		}	
		
		
	}
	
	return 0;
}